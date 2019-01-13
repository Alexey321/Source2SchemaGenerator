#include "SchemaSystem.hpp"

#include "Interface.hpp"


namespace schema {
    SchemaSystem* SchemaSystem::Get() {
        static SchemaSystem* schemaSystem = Interface<SchemaSystem>::Get("schemasystem.dll", "SchemaSystem_001");
        return schemaSystem;
    }

    CSchemaSystemTypeScope* SchemaSystem::GlobalTypeScope() {
        return (GetVirtual<CSchemaSystemTypeScope* (__thiscall*)(SchemaSystem*)>(this, s_globalTypeScopeIndex))(this);
    }

    CSchemaSystemTypeScope* SchemaSystem::FindTypeScopeForModule(const char* module) {
        return (GetVirtual<CSchemaSystemTypeScope* (__thiscall*)(SchemaSystem*, const char*)>(this, s_findTypeScopeForModuleIndex))(this, module);
    }


    CSchemaClassInfo* CSchemaSystemTypeScope::FindDeclaredClass(const char* name) {
        return (GetVirtual<CSchemaClassInfo* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, s_findDeclaredClassIndex))(this, name);
    }

    CSchemaEnumInfo* CSchemaSystemTypeScope::FindDeclaredEnum(const char* name) {
        return (GetVirtual<CSchemaEnumInfo* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, s_findDeclaredEnumIndex))(this, name);
    }

    CSchemaType* CSchemaSystemTypeScope::FindSchemaTypeByName(const char* name) {
        return (GetVirtual<CSchemaType* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, 4))(this, name);
    }

    CSchemaType* CSchemaSystemTypeScope::FindType_DeclaredClass(const char* name) {
        return (GetVirtual<CSchemaType* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, s_findType_DeclaredClassIndex))(this, name);
    }

    CSchemaType* CSchemaSystemTypeScope::FindType_DeclaredEnum(const char* name) {
        return (GetVirtual<CSchemaType* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, s_findType_DeclaredEnumIndex))(this, name);
    }

    CSchemaClassBinding* CSchemaSystemTypeScope::FindRawClassBinding(const char* name) {
        return (GetVirtual<CSchemaClassBinding* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, s_findRawClassBindingIndex))(this, name);
    }

    CSchemaEnumBinding* CSchemaSystemTypeScope::FindRawEnumBinding(const char* name) {
        return (GetVirtual<CSchemaEnumBinding* (__thiscall*)(CSchemaSystemTypeScope*, const char*)>(this, s_findRawEnumBindingIndex))(this, name);
    }

    void CSchemaSystemTypeScope::FillClassBindingList(std::vector<CSchemaClassBinding*>& classBinding) {
        //auto schemaList = GetClassList();
		auto schemaList = (SchemaList<CSchemaClassBinding>*)0x7FFED8C1C1E8;


        if (!schemaList) {
            return;
        }

        unsigned int blockIndex = 0;

        for (auto& schemaIterator : schemaList->GetBlockContainers()) {
            for (auto block = schemaIterator.GetFirstBlock(); block && blockIndex < schemaList->GetNumSchema(); block = block->Next(), ++blockIndex) {
                auto binding = block->GetBinding();

                if (!binding) {
                    continue;
                }

                if (binding && binding->m_classInfo && binding->m_classInfo->m_Name.data) {
                    classBinding.push_back(binding);
                }
            }
        }
    }

    void CSchemaSystemTypeScope::FillEnumInfoList(std::vector<CSchemaEnumInfo*>& enumInfo) {
        //auto schemaList = GetEnumList();
		auto schemaList = (SchemaList<CSchemaEnumBinding>*)0x7FFED8C1E230;


		std::ofstream Log("C:\\Users\\root\\Downloads\\Source2Gen-master\\bin\\Debug\\Log.txt", std::ofstream::out | std::ofstream::app);
		Log << "	GetEnumList: " << std::hex << schemaList << std::endl;
		Log << "	schemaList->GetNumSchema(): " << schemaList->GetNumSchema() << std::endl;
		Log << "	schemaList->GetBlockContainers()[0].GetFirstBlock(): " << schemaList->GetBlockContainers()[0].GetFirstBlock() << std::endl;
		Log << "	schemaList->GetBlockContainers()[0].GetFirstBlock()->GetBinding(): " << schemaList->GetBlockContainers()[0].GetFirstBlock()->GetBinding() << std::endl;

		//_sleep(9999999999999999999);

        if (!schemaList) {
            return;
        }


        unsigned int blockIndex = 0;
		//__debugbreak();
        for (auto& schemaIterator : schemaList->GetBlockContainers()) {
            for (auto block = schemaIterator.GetFirstBlock(); block && blockIndex < schemaList->GetNumSchema(); block = block->Next(), ++blockIndex) {
				//__debugbreak();
				auto binding = block->GetBinding();

                if (!binding) {
                    continue;
                }

                if (binding && binding->m_enumInfo && binding->m_enumInfo->m_Name.data) {
                    enumInfo.push_back(binding->m_enumInfo);
                }
            }
        }
		Log << "	blockIndex: " << blockIndex << std::endl;

		//__debugbreak();

    }

}