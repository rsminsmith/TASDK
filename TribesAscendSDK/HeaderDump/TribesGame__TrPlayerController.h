#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPlayerController : public UTPlayerController
	{
	public:
			ADD_VAR( ::BoolProperty, m_bShowHUDCracks, 0x100000 )
			ADD_OBJECT( TrEquipInterface, m_TrEquipInterface )
			ADD_VAR( ::BoolProperty, m_bShowSpectatorHUD, 0x10000000 )
			ADD_VAR( ::BoolProperty, m_bShowSpectatorControls, 0x8000000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDVisor, 0x100 )
			ADD_VAR( ::BoolProperty, m_bShowHUDHealthBar, 0x80 )
			ADD_VAR( ::BoolProperty, m_bShowHUDHeroText, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDKillbox, 0x800 )
			ADD_VAR( ::BoolProperty, m_bShowHUDCombatLog, 0x400 )
			ADD_VAR( ::BoolProperty, m_bShowHUDSkiBars, 0x10000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDCredits, 0x8 )
			ADD_VAR( ::BoolProperty, m_bShowHUDReticule, 0x4 )
			ADD_VAR( ::BoolProperty, m_bShowHUDChat, 0x200 )
			ADD_VAR( ::BoolProperty, m_bShowHUDPromptPanel, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDDeathcam, 0x1000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDRespawnTimer, 0x8000 )
			ADD_VAR( ::FloatProperty, r_fRespawnTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIsRovingSpectating, 0x20000000 )
			ADD_VAR( ::BoolProperty, m_bViewThroughDeathCamera, 0x400000 )
			ADD_OBJECT( AlienFXManager, AlienFX )
			ADD_VAR( ::BoolProperty, EnableAlienFX, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDScores, 0x40 )
			ADD_VAR( ::IntProperty, m_nLastDamagerUpgradeLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLastDamagerHealthPercent, 0xFFFFFFFF )
			ADD_OBJECT( TrStrings, Strings )
			ADD_OBJECT( TrInventoryHelper, m_TrInventoryHelper )
			ADD_VAR( ::BoolProperty, m_bShowHUDBadges, 0x20 )
			ADD_VAR( ::BoolProperty, m_bShowHUDAccolades, 0x10 )
			ADD_VAR( ::BoolProperty, r_bNeedTeam, 0x8000 )
			ADD_VAR( ::BoolProperty, r_bNeedLoadout, 0x10000 )
			ADD_VAR( ::BoolProperty, r_bDailyCompleted, 0x2000000 )
			ADD_VAR( ::IntProperty, m_RequestedTeam, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoRevertSetting, 0x2000000 )
			ADD_VAR( ::FloatProperty, m_fLastHitEnemyTime, 0xFFFFFFFF )
			ADD_OBJECT( TrPlayerController, m_LastKilledBy )
			ADD_VAR( ::ByteProperty, r_nHitEnemyHeadshot, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bAllowSimulatedProjectiles, 0x400000 )
			ADD_VAR( ::BoolProperty, c_bPressingZoomButton, 0x200 )
			ADD_OBJECT( TrHelpTextManager, m_HelpTextManager )
			ADD_STRUCT( ::RotatorProperty, m_rCurrentKickbackDirection, 0xFFFFFFFF )
			ADD_OBJECT( MaterialEffect, m_ZoomedEffect )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_OBJECT( TrAccoladeManager, m_AccoladeManager )
			ADD_STRUCT( ::VectorProperty, m_vDeathCamOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeathCameraCurrentScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeathCameraInnerScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeathCameraInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_BeginPlayedTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bPressingJetpack, 0x4 )
			ADD_OBJECT( Actor, m_LastDamagedBy )
			ADD_VAR( ::IntProperty, FriendlyFireDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastFlagGrabTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bShowHUDFriendColoring, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bEjectedFromVehicle, 0x10000000 )
			ADD_VAR( ::BoolProperty, m_bLastDeathWasUserSuicide, 0x200000 )
			ADD_VAR( ::IntProperty, FriendlyFireKills, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_ZoomState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFreeCamYawOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFreeCamPitchOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCallInCooldown, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nCallinCooldownFlash, 0xFFFFFFFF )
			ADD_OBJECT( TrChatConsoleCommands, m_PlayerCommands )
			ADD_VAR( ::FloatProperty, fSniperRespawnDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSuicideTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VGSClassId, 0xFFFFFFFF )
			ADD_OBJECT( TrContentLoader, c_ContentLoader )
			ADD_VAR( ::IntProperty, m_WhisperFilter, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, r_rViewTargetViewRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vViewTargetViewLocation, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, r_ViewTargetVehiclePassengerPRI )
			ADD_OBJECT( PlayerReplicationInfo, r_ViewTargetVehicleDriverPRI )
			ADD_VAR( ::FloatProperty, r_fViewTargetVehicleMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetVehicleCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetPackAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetOffhandAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetSecondaryMaxAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetPrimaryMaxAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetSecondaryAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetPrimaryAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetCurrentPowerpool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetNextRegenTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxVGSSoundChannels, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_TeamRabbitAssistCredit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_TeamAssistCredit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_DamageNeededForCredit, 0xFFFFFFFF )
			ADD_OBJECT( MaterialEffect, m_RoundEndedME )
			ADD_VAR( ::FloatProperty, m_fDeterminationAccumulator, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeterminationAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LoadingScreenTimeout, 0xFFFFFFFF )
			ADD_OBJECT( TrPaperDoll, m_PaperDoll )
			ADD_VAR( ::FloatProperty, m_fDeathCameraOuterScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fUserSuicideTimePenalty, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpamLockoutTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLockoutFromSpamTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMessageSpamTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_fMaxBroadcastSpamCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSpotTargetTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, s_nNewPlayerAssistPoints, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, s_nMaxNewPlayerAssistPoints, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, s_fNewPlayerAssistMitigateCauseDamageMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, s_fNewPlayerAssistMitigateTakeDamageMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFlagGrabSpeedRecord, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFlagCapSpeedRecord, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiSpeedRecord, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCheckTotal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSpeedCheckCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSpeedCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCheckInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHideJetpackHelpTextDistanceThresholdSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTotalDistanceJetpackedSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHideSkiHelpTextDistanceThresholdSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastDistanceSkiedSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastDistanceCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDistanceCheckInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTotalDistanceSkiedSq, 0xFFFFFFFF )
			ADD_OBJECT( TrVehicle, m_LastAcknowledgedVehicle )
			ADD_VAR( ::IntProperty, m_ActiveClassId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_LastVGSUse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIdleCheckTimer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedVZeroSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedPPTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedPPAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedPPInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCameraSpeedSqared, 0xFFFFFFFF )
			ADD_OBJECT( UDKEmitCameraEffect, m_WeatherCameraEffect )
			ADD_OBJECT( UDKEmitCameraEffect, m_SpeedCameraEffect )
			ADD_VAR( ::IntProperty, m_nLatestAccoladeIcon, 0xFFFFFFFF )
			ADD_OBJECT( TrCameraModifier_CameraShake, m_CameraShake )
			ADD_OBJECT( Weapon, m_LastWeaponEquipped )
			ADD_VAR( ::IntProperty, m_VehicleSeatIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_LastPressedSkiTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinActiveSkiTimeToEnableFollowthough, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiFollowthroughTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, r_KilledBy )
			ADD_VAR( ::FloatProperty, m_LastLoadoutRequestTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nClientSpawnTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRespawnTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPlayBeginTime, 0xFFFFFFFF )
			ADD_OBJECT( TrAnnouncer, m_Announcer )
			ADD_OBJECT( TrMusicManager, m_MusicManager )
			ADD_VAR( ::FloatProperty, c_fHUDZoomDuration, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_nCallinCooldownFlashStored, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_nLastHitEnemyHeadshot, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nHitEnemy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, c_fZoomButtonPressedTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fZoomRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDesiredMagnifiedZoomFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDesiredZoomFOV, 0xFFFFFFFF )
			ADD_OBJECT( TrStation, m_CurrentStation )
			ADD_VAR( ::IntProperty, r_nCurrentCredits, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_RicochetSound3P )
			ADD_OBJECT( SoundCue, m_MissileSeekingSelfCue )
			ADD_OBJECT( SoundCue, m_MissileFiredCue )
			ADD_OBJECT( SoundCue, m_MissileLockedCue )
			ADD_OBJECT( SoundCue, m_MissileLockingCue )
			ADD_VAR( ::IntProperty, m_OverwatchTeam, 0xFFFFFFFF )
			ADD_OBJECT( CameraActor, m_OverwatchCam )
			ADD_STRUCT( ::RotatorProperty, m_rKickbackAim, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastKickbackViewTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fKickbackViewBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fKickbackViewBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingInitiatingJettingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWarmingUp, 0x20000000 )
			ADD_VAR( ::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x8000000 )
			ADD_VAR( ::BoolProperty, m_bEnableChatFilter, 0x4000000 )
			ADD_VAR( ::BoolProperty, bBlockForAcquisition, 0x1000000 )
			ADD_VAR( ::BoolProperty, m_bAnimMenu, 0x200000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDFriendStateNotifications, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDNotifications, 0x40000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDObjectives, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEnableOverheadDamageIndicators, 0x1 )
			ADD_VAR( ::BoolProperty, r_bViewTargetVehicleSecondaryWeaponReady, 0x80000000 )
			ADD_VAR( ::BoolProperty, r_bViewTargetVehiclePrimaryWeaponReady, 0x40000000 )
			ADD_VAR( ::BoolProperty, r_bWeeklyCompleted, 0x4000000 )
			ADD_VAR( ::BoolProperty, m_bIsJumpJetting, 0x1000000 )
			ADD_VAR( ::BoolProperty, m_bJustJoined, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bMonkeyMode, 0x100000 )
			ADD_VAR( ::BoolProperty, m_bJetpackHelpTextThresholdReached, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bSkiHelpTextThresholdReached, 0x40000 )
			ADD_VAR( ::BoolProperty, m_bEnableCameraSpeedEffect, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bLoadoutChangeAlerted, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bRequestingSki, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bPlayerSwappedTeams, 0x1000 )
			ADD_VAR( ::BoolProperty, m_bReturnTo3PAfterZoom, 0x800 )
			ADD_VAR( ::BoolProperty, m_bZoomMagnified, 0x400 )
			ADD_VAR( ::BoolProperty, m_bPlayCreditsSound, 0x100 )
			ADD_VAR( ::BoolProperty, bWasAutoBalanced, 0x80 )
			ADD_VAR( ::BoolProperty, m_bAftermathKill, 0x40 )
			ADD_VAR( ::BoolProperty, m_bKickbackBlendingIn, 0x20 )
			ADD_VAR( ::BoolProperty, m_bBlink, 0x10 )
			ADD_VAR( ::BoolProperty, m_bJumpJet, 0x8 )
			ADD_VAR( ::BoolProperty, m_bPressingJetpackButton, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEditorMode, 0x1 )
			ADD_VAR( ::FloatProperty, m_fLastWeaponSwitchTimestamp, 0xFFFFFFFF )
			ADD_OBJECT( Actor, m_aHoverActor )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
