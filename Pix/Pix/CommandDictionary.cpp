#include "CommandDictionary.h"

#include "CmdDrawPixel.h"
#include "CmdSetResolution.h"
#include "CmdVarFloat.h"
#include "CmdVarBool.h"
#include "CmdSetColor.h"
#include "CmdSetFillMode.h"

#include "CmdBeginDraw.h"
#include "CmdEndDraw.h"
#include "CmdVertex.h"

#include "CmdShowViewport.h"
#include "CmdSetViewport.h"
#include "CmdSetClipping.h"
#include "CmdMatrix.h"
#include "CmdCamera.h"
#include "CmdSetCullMode.h"
#include "CmdEnableDepth.h"

#include "CmdMaterial.h"

//#include "MathHelper.h"

CommandDictionary* CommandDictionary::Get()
{
	static CommandDictionary sInstance;
	return &sInstance;
}

CommandDictionary::CommandDictionary()
{
	// Initialize dictionary

	// Setting commands
	RegisterCommand<CmdSetResolution>();

	// Variable commands
	RegisterCommand<CmdVarFloat>();
	RegisterCommand<CmdVarBool>();

	// Rasterization commands
	RegisterCommand<CmdDrawPixel>();
	RegisterCommand<CmdSetColor>();
	RegisterCommand<CmdSetFillMode>();
	RegisterCommand<CmdEnableDepth>();

	// Primitive commands
	RegisterCommand<CmdBeginDraw>();
	RegisterCommand<CmdEndDraw>();
	RegisterCommand<CmdVertex>();
	RegisterCommand<CmdSetCullMode>();

	// Viewport commands
	RegisterCommand<CmdShowViewport>();
	RegisterCommand<CmdSetViewport>();
	RegisterCommand<CmdSetClipping>();

	//Matrix4 rotX = Matrix4::RotationX((45.0f * 3.141592f) / 180.0f);
	//Matrix4 trans = Matrix4::Translation(10.0f, 5.0f, 3.0f);
	//Matrix4 final = rotX * trans;
	//Matrix4 invFinal = MathHelper::Inverse(final);
	//Matrix4 identity = final * invFinal;

	//Matrix commands
	RegisterCommand<CmdPushTranslation>();
	RegisterCommand<CmdPushRotationX>();
	RegisterCommand<CmdPushRotationY>();
	RegisterCommand<CmdPushRotationZ>();
	RegisterCommand<CmdPushScaling>();
	RegisterCommand<CmdPopMatrix>();

	// Camera commands
	RegisterCommand<CmdSetCameraPosition>();
	RegisterCommand<CmdSetCameraDirection>();
	RegisterCommand<CmdSetCameraNear>();
	RegisterCommand<CmdSetCameraFar>();
	RegisterCommand<CmdSetCameraFov>();

	// Material commands
	RegisterCommand<CmdSetMaterialEmissive>();
	RegisterCommand<CmdSetMaterialAmbient>();
	RegisterCommand<CmdSetMaterialDiffuse>();
	RegisterCommand<CmdSetMaterialSpecular>();
	RegisterCommand<CmdSetMaterialShininess>();
}

TextEditor::LanguageDefinition CommandDictionary::GenerateLanguageDefinition()
{
	TextEditor::LanguageDefinition langDef;

	langDef.mName = "Pix";

	langDef.mKeywords.insert("var");

	for (auto& [keyword, command] : mCommandMap)
	{
		TextEditor::Identifier id;
		id.mDeclaration = command->GetDescription();
		langDef.mIdentifiers.insert(std::make_pair(keyword, id));
	}

	langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("\\$[a-zA-Z_]+", TextEditor::PaletteIndex::Keyword));
	langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("L?\\\"(\\\\.|[^\\\"])*\\\"", TextEditor::PaletteIndex::String));
	langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("\\'\\\\?[^\\']\\'", TextEditor::PaletteIndex::CharLiteral));
	langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?", TextEditor::PaletteIndex::Number));
	langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[a-zA-Z_][a-zA-Z0-9_]*", TextEditor::PaletteIndex::Identifier));
	langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.]", TextEditor::PaletteIndex::Punctuation));

	langDef.mCommentStart = "/*";
	langDef.mCommentEnd = "*/";
	langDef.mSingleLineComment = "//";

	langDef.mAutoIndentation = true;
	langDef.mCaseSensitive = true;

	return langDef;
}

Command* CommandDictionary::CommandLookup(const std::string& keyword)
{
	auto iter = mCommandMap.find(keyword);
	if (iter == mCommandMap.end())
		return nullptr;
	return iter->second.get();
}

template <class T>
void CommandDictionary::RegisterCommand()
{
	static_assert(std::is_base_of_v<Command, T>, "Invalid command type.");
	auto newCommand = std::make_unique<T>();
	mCommandMap.emplace(newCommand->GetName(), std::move(newCommand));
}