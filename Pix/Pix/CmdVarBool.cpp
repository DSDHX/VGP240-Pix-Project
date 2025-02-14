#include "CmdVarBool.h"
#include "VariableCache.h"

bool CmdVarBool::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3) { return false; }
	
	VariableCache* vc = VariableCache::Get();
	if (!vc->IsVarName(params[0]) || params[1] != "=") { return false; }

	const bool value = params[2] == "true";
	vc->AddBool(params[0], value);
	return true;
}
