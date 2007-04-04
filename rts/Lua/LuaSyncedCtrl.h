#ifndef LUA_SYNCED_CTRL_H
#define LUA_SYNCED_CTRL_H
// LuaSyncedCtrl.h: interface for the LuaSyncedCtrl class.
//
//////////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif


struct lua_State;


class LuaSyncedCtrl {
	public:
		static bool PushEntries(lua_State* L);

		static void SetAllowGameChanges(bool value);
		static bool GetAllowGameChanges();

		static void CheckAllowGameChanges(lua_State* L);

	private:
		static bool allowGameChanges;
		static bool inCreateUnit;
		static bool inDestroyUnit;
		static bool inTransferUnit;
		static bool inCreateFeature;
		static bool inDestroyFeature;
		static bool inGiveOrder;

	private:
		// all LuaHandleSynced
		static int SendMessage(lua_State* L);
		static int SendMessageToPlayer(lua_State* L);
		static int SendMessageToTeam(lua_State* L);
		static int SendMessageToAllyTeam(lua_State* L);
		static int SendMessageToSpectators(lua_State* L);

		static int SetTeamResources(lua_State* L);
		static int SetTeamShareLevel(lua_State* L);

		static int CallCOBScript(lua_State* L);
		static int CallCOBScriptCB(lua_State* L);
		static int GetCOBScriptID(lua_State* L);

		static int GiveOrderToUnit(lua_State* L);
		static int GiveOrderToUnitMap(lua_State* L);
		static int GiveOrderToUnitArray(lua_State* L);
		static int GiveOrderArrayToUnitMap(lua_State* L);
		static int GiveOrderArrayToUnitArray(lua_State* L);

		static int CreateUnit(lua_State* L);
		static int DestroyUnit(lua_State* L);
		static int TransferUnit(lua_State* L);

		static int CreateFeature(lua_State* L);
		static int DestroyFeature(lua_State* L);
		static int TransferFeature(lua_State* L);

		static int SetUnitTooltip(lua_State* L);
		static int SetUnitHealth(lua_State* L);
		static int SetUnitMaxHealth(lua_State* L);
		static int SetUnitStockpile(lua_State* L);
		static int SetUnitExperience(lua_State* L);
		static int SetUnitStealth(lua_State* L);
		static int SetUnitNoSelect(lua_State* L);
		static int SetUnitNoMinimap(lua_State* L);
		static int SetUnitAlwaysVisible(lua_State* L);
		static int SetUnitMetalExtraction(lua_State* L);

		static int SetUnitPhysics(lua_State* L);
		static int SetUnitPosition(lua_State* L);
		static int SetUnitRotation(lua_State* L);
		static int SetUnitVelocity(lua_State* L);

		static int SetFeatureHealth(lua_State* L);
		static int SetFeatureReclaim(lua_State* L);
		static int SetFeatureResurrect(lua_State* L);
		static int SetFeaturePosition(lua_State* L);
		static int SetFeatureDirection(lua_State* L);

		static int LevelHeightMap(lua_State* L);
		static int AdjustHeightMap(lua_State* L);
		static int RevertHeightMap(lua_State* L);

		// LuaCob and LuaRules  (fullCtrl)
		static int EditUnitCmdDesc(lua_State* L);
		static int InsertUnitCmdDesc(lua_State* L);
		static int RemoveUnitCmdDesc(lua_State* L);
};


#endif /* LUA_SYNCED_CTRL_H */
