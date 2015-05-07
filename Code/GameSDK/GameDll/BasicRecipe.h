/****************************************
* File: Recipe.h
* Description: ������� ������ - ������
* Created by: Andrew Medvedev
* Date: 22.08.2013
* Diko Source File
*****************************************/

#ifndef _RECIPE_GAME_OBJECT_
#define _RECIPE_GAME_OBJECT_

#include "BasicObject.h"

class CBasicRecipe : public IBasicObject
{
public:
	CBasicRecipe();
	// IGameObjectExtension
	bool Init(IGameObject * pGameObject);
	void PostInit(IGameObject * pGameObject);
	void InitClient(int channelId){}
	void PostInitClient(int channelId){}

	bool ReloadExtension(IGameObject * pGameObject, const SEntitySpawnParams &params){ return true; }
	void PostReloadExtension(IGameObject * pGameObject, const SEntitySpawnParams &params){}
	bool GetEntityPoolSignature(TSerialize signature){ return true; }
	void Release();

	void FullSerialize(TSerialize ser);
	bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int pflags){ return true; }
	void PostSerialize(){}
	void SerializeSpawnInfo(TSerialize ser){}
	ISerializableInfoPtr GetSpawnInfo(){ return 0; }

	void Update(SEntityUpdateContext& ctx, int updateSlot);
	void HandleEvent(const SGameObjectEvent& event){}
	void ProcessEvent(SEntityEvent& event);

	void SetChannelId(uint16 id){}
	void SetAuthority(bool auth){}

	void PostUpdate(float frameTime){}
	void PostRemoteSpawn(){}
	void GetMemoryUsage(ICrySizer* s) const{ s->Add(this); }
	//~ IGameObjectExtension

	void OnUse();
	void Reset();
	void OnPickUp(EntityId id);
	void OnDrop(SInventoryItem* pItem, EntityId id);
	void Physicalize(int type);

	SInventoryItem* GetItemParamsXML();
	SmartScriptTable GetSmartScriptTable();

	string GetObjectName(){ return m_ObjectName; }
	string GetObjetDescription(){ return m_ObjectDescr; }
	string GetModelPath(){ return m_ModelPath; }
	string GetEntityType(){ return m_EntityType; }
	
private:
	string m_sRecipeName;
};

#endif