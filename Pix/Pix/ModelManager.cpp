#include "ModelManager.h"

ModelManager* ModelManager::Get()
{
    static ModelManager sInstance;
    return &sInstance;
}

void ModelManager::Clear()
{
    mModels.clear();
}

const Model* ModelManager::GetModel(const std::string& filename)
{
    auto iter = std::find_if(mModels.begin(), mModels.end(), [filename](auto& model)
        {
            return model->GetFileName() == filename;
        });
    if (iter != mModels.end())
    {
        return iter->get();
    }

    auto& model = mModels.emplace_back(std::make_unique<Model>());
    model->Load(filename);
    return model.get();
}