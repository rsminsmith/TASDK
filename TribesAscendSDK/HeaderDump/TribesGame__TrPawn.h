#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPawn : public UTPawn
	{
	public:
			float GetCurrentPowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetCurrentPowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetMaxPowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetMaxPowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrVehicle, m_RidingVehicle )
			int CalculatePawnSpeed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CalculatePawnSpeed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptClass* GetCurrCharClassInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetCurrCharClassInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			bool IsFirstPerson(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.IsFirstPerson" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class SkeletalMesh* GetHandsMesh( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetHandsMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			class TrPlayerReplicationInfo* GetTribesReplicationInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetTribesReplicationInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrPlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF )
			bool CheckHeadShot( void* &Impact )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CheckHeadShot" );
				byte *params = ( byte* )( malloc( 80 ) );
				*( void** )( params + 0 ) = Impact;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Impact = *( void** )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fHeadShotDamageMultiple, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentAccuracy, 0xFFFFFFFF )
			Vector GetPawnViewLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetPawnViewLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fPawnViewForwardAmount, 0xFFFFFFFF )
			class TrHUD* GetTrHud(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetTrHud" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrHUD** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrAnimNodeBlendByRidingPassenger, m_RidingPassengerBlendNode )
			ADD_OBJECT( TrAnimNodeAimOffset, m_AimOffsetNode )
			ADD_OBJECT( TrAnimNodeAimOffset, m_1pBodyAimOffsetNode )
			ADD_STRUCT( ::VectorProperty, r_FlashNormal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShowObjectThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bIsStealthed, 0x4 )
			bool IsPulseStealthed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.IsPulseStealthed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsJammedByFriendOrSelf(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.IsJammedByFriendOrSelf" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, r_bIsInvulnerable, 0x100000 )
			ADD_VAR( ::BoolProperty, r_bIsSkiing, 0x800 )
			ADD_VAR( ::BoolProperty, r_bIsJetting, 0x8000 )
			ADD_VAR( ::FloatProperty, m_TerrainWalkableFloorZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSwapSkinDistSq, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, c_Pending1PSkin )
			ADD_OBJECT( ScriptClass, c_Pending3PSkin )
			ADD_VAR( ::IntProperty, m_nNetViewPitchCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_PitchInterpRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTargetRemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPreviousReceivedRemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nSmoothedRemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNetRotationCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RotationInterpRate, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_TargetNetReceiveRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_PreviousNetReceiveRotation, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, m_GibMesh )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_VAR( ::FloatProperty, m_fInventoryStationLockoutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastInventoryStationVisitTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF )
			ADD_OBJECT( UDKCarriedObject, m_GameObjCheckTimer )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_HealthBarMIC )
			ADD_OBJECT( UTWeaponAttachment, m_InHandWeaponAttachmentFromAutoFire )
			ADD_VAR( ::FloatProperty, m_fLastTakeClotheslineDamageTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineSpeedDifferenceMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineSpeedDifferenceMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineDamageMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClotheslineDamageMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatSpeedMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatSpeedMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromWallMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromWallMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromLandMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSplatDamageFromLandMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_bJustLandedSpeedSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fGroundSkiEffectDist, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_InvulnerableOverlayMIC )
			ADD_OBJECT( Material, m_InvulnerableOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_RageOverlayMIC )
			ADD_OBJECT( Material, m_RageOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_JammerPackOverlayMIC )
			ADD_OBJECT( Material, m_JammerPackOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_RegenPackPackOverlayMIC )
			ADD_OBJECT( Material, m_RegenPackOverlayMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_RegenOverlayMIC )
			ADD_OBJECT( Material, m_RegenOverlayMaterial )
			ADD_VAR( ::FloatProperty, m_fShieldPackMaterialHitRampDownSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOverlayMaterialDeactivateSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOverlayMaterialActivateSpeed, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ShieldPackOverlayMIC )
			ADD_OBJECT( Material, m_ShieldPackOverlayMaterial )
			ADD_VAR( ::FloatProperty, m_fForwardJettingPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxJetpackBoostGroundspeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nEnemyDropJammerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nFriendlyDropJammerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nEnemyJamCount, 0xFFFFFFFF )
			ADD_OBJECT( TrPlayerReplicationInfo, r_FriendJammingPRI )
			ADD_VAR( ::IntProperty, m_JammingFriendTeam, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fJamEffectRadius, 0xFFFFFFFF )
			ADD_OBJECT( TrPawnCollisionProxy, m_JammingCollisionProxy )
			ADD_OBJECT( Material, r_ReplicatedWeaponAttachmentMat )
			ADD_VAR( ::FloatProperty, m_OldSpeed, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_avMultiShotLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fEnemyShowDistanceThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFriendlyShowDistanceThreshold, 0xFFFFFFFF )
			ADD_OBJECT( MorphNodeWeight, m_OverlayMorphNode )
			ADD_OBJECT( TrAnimNodeBlendByVehicle, m_VehicleBlendNode )
			ADD_VAR( ::FloatProperty, m_fFallVelocityTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastDamagerTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastVehicleDamagerTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_AssistDamagePercentQualifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiAccelPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiAccelCapSpeedThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAirAccelSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAirAccelCapSpeedThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTerminalSkiSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSkiSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiSlopeGravityBoost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSkiControlPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiControlSigmaSquare, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPeakSkiControlSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nSensorAlertLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDecelerationRateWithFlag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSpeedWithFlag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPreserveVelocityZNormalThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPreserveVelocityThresholdMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPreserveVelocityThresholdMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxSpeedDecelerationRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTerminalJettingSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxJettingSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccelRateAtMaxThrustSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxJetpackThrustSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxStoppingDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fStoppingDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHeadShotFudge, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTickedRegenDecimal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSecondsBeforeAutoHeal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fPowerPoolRechargeRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastUntargetByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastTargetByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastUnseenByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeLastSeenByLocalPlayer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, s_fVE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShieldMultiple, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fFasterWeaponSwitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthIgnoreTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthIgnoreTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fPulseStealthSpeedThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthFadeInInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthVisibleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseStealthVisibleTimestamp, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_StealthMIC )
			ADD_OBJECT( Material, m_StealthMaterial )
			ADD_VAR( ::FloatProperty, m_fMinStealthVisibilityParamValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDisableStealthVisibilityInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fEnableStealthVisibilityInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LastFXOverlay, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nWhiteOut, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_RemoteViewYaw, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PhysType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nFactionId, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nBlinked, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nPulseStealth, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_MissileLock, 0xFFFFFFFF )
			ADD_OBJECT( Actor, r_LockedTarget )
			ADD_VAR( ::BoolProperty, m_bUseSmoothNetReceiveRotation, 0x1000000 )
			ADD_VAR( ::BoolProperty, r_bDetectedByEnemyScanner, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bSplattedAgainstWall, 0x400000 )
			ADD_VAR( ::BoolProperty, m_bIsInConduit, 0x200000 )
			ADD_VAR( ::BoolProperty, m_bUpdateStickyGrenades, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bLoadoutReset, 0x40000 )
			ADD_VAR( ::BoolProperty, r_bIsJamming, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bIsJetEffectsPlaying, 0x10000 )
			ADD_VAR( ::BoolProperty, r_bAimingMode, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bIsPlayingSkiEffectsSounds, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bIsPlayingSkiEffects, 0x1000 )
			ADD_VAR( ::BoolProperty, bInDeployModeClient, 0x400 )
			ADD_VAR( ::BoolProperty, r_bInDeployMode, 0x200 )
			ADD_VAR( ::BoolProperty, bInFireLockClient, 0x100 )
			ADD_VAR( ::BoolProperty, r_bInFireLock, 0x80 )
			ADD_VAR( ::BoolProperty, r_bIsHealthRecharging, 0x40 )
			ADD_VAR( ::BoolProperty, r_bIsShielded, 0x20 )
			ADD_VAR( ::BoolProperty, r_bIsRaged, 0x10 )
			ADD_VAR( ::BoolProperty, m_bStealthVisible, 0x8 )
			ADD_VAR( ::BoolProperty, m_bRefreshInventoryWasRespawn, 0x2 )
			ADD_VAR( ::BoolProperty, m_bInitialized, 0x1 )
			ADD_VAR( ::NameProperty, m_nmMakeVisible, 0xFFFFFFFF )
			void CheckGrabSpeed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CheckGrabSpeed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float NativeGetCollisionHeight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.NativeGetCollisionHeight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float NativeGetCollisionRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.NativeGetCollisionRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SyncClientCurrentPowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SyncClientCurrentPowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsumePowerPool( float fAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ConsumePowerPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = fAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegainPowerPool( float fDeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RegainPowerPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = fDeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetPowerPoolPercent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetPowerPoolPercent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void GetCurrentDeviceAccuracyInfo( float &fAccuracy, float &fAmountCurrentlyOffOfTargetAccuray )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetCurrentDeviceAccuracyInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = fAccuracy;
				*( float* )( params + 4 ) = fAmountCurrentlyOffOfTargetAccuray;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				fAccuracy = *( float* )( params + 0 );
				fAmountCurrentlyOffOfTargetAccuray = *( float* )( params + 4 );
			}

			void SetOverlayMaterial( class MaterialInterface* NewOverlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetOverlayMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )( params + 0 ) = NewOverlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ServerUpdateLockedTarget( class Actor* Locked )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ServerUpdateLockedTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Locked;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NativePostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.NativePostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetTargetLocation( class Actor* RequestedBy, bool bRequestAlternateLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetTargetLocation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = RequestedBy;
				*( bool* )( params + 4 ) = bRequestAlternateLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetFlashNormal( Vector FlashNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetFlashNormal" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = FlashNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetCurrentCredits(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetCurrentCredits" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ClientRestart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClientRestart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int CurrentDeployedCount( ScriptClass* DeviceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CurrentDeployedCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = DeviceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ExitDeployMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ExitDeployMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetArmorType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetArmorType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicateMultiFlashLocation( int shotNumber, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ReplicateMultiFlashLocation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = shotNumber;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EquipBestPossibleDevice( byte eqpPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.EquipBestPossibleDevice" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = eqpPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitDefaultAnims( ScriptClass* Info )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.InitDefaultAnims" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = Info;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCharacterClassFromInfo( ScriptClass* Info, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetCharacterClassFromInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = Info;
				*( bool* )( params + 4 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivatePendingClass( bool bIsRespawn, bool bCallin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ActivatePendingClass" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bIsRespawn;
				*( bool* )( params + 4 ) = bCallin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshInventoryTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RefreshInventoryTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetValuesFromCurrentFamilyInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetValuesFromCurrentFamilyInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshInventory( bool bIsRespawn, bool bCallin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RefreshInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bIsRespawn;
				*( bool* )( params + 4 ) = bCallin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateSelectedDeployable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ActivateSelectedDeployable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveEffectByClass( ScriptClass* efClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RemoveEffectByClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = efClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessEffectForm( ScriptClass* efClass, bool bRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ProcessEffectForm" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = efClass;
				*( bool* )( params + 4 ) = bRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetShieldStrength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetShieldStrength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void AdjustAmmoPool( float Change )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.AdjustAmmoPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Change;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustMaxPowerPool( float Change )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.AdjustMaxPowerPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Change;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMaxPowerPool( int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetMaxPowerPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMaxHealthPool( int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetMaxHealthPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientUpdateHUDHealth( int NewHealth, int NewHealthMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClientUpdateHUDHealth" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = NewHealth;
				*( int* )( params + 4 ) = NewHealthMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldRechargePowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ShouldRechargePowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ForceHealthRegen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ForceHealthRegen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RechargeHealthPool( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RechargeHealthPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetJetpackAirControl( Vector InAcceleration, Vector ZAxis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetJetpackAirControl" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = InAcceleration;
				*( Vector* )( params + 12 ) = ZAxis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void UpdateSkiEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.UpdateSkiEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayJetpackEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayJetpackEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateJetpackEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.UpdateJetpackEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopJetpackEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StopJetpackEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayLandingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayLandingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayJumpingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayJumpingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RememberLastDamager( class Controller* Damager, int DamageAmount, class Actor* DamagingActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RememberLastDamager" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )( params + 0 ) = Damager;
				*( int* )( params + 4 ) = DamageAmount;
				*( class Actor** )( params + 8 ) = DamagingActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetHealthPct(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetHealthPct" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void* CreateAssistRecord( class Controller* Damager, int DamageAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CreateAssistRecord" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Damager;
				*( int* )( params + 4 ) = DamageAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			class TrPlayerController* GetLastDamager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetLastDamager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrPlayerController** )( params + function->return_val_offset() );
			}

			void ProcessKillAssists( class Controller* Killer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ProcessKillAssists" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = Killer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetUnshieldedDamage( float inputDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetUnshieldedDamage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = inputDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class TrPawn* GetPawnCausingDamage( class Controller* EventInstigator, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetPawnCausingDamage" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = EventInstigator;
				*( class Actor** )( params + 4 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrPawn** )( params + function->return_val_offset() );
			}

			float GetDamageScale( class Actor* DamageCauser, float Dist, ScriptClass* dmgType, class Controller* EventInstigator, class TrValueModifier* VM, float &DamageScaleWithoutNewPlayerAssist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetDamageScale" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )( params + 0 ) = DamageCauser;
				*( float* )( params + 4 ) = Dist;
				*( ScriptClass** )( params + 8 ) = dmgType;
				*( class Controller** )( params + 12 ) = EventInstigator;
				*( class TrValueModifier** )( params + 16 ) = VM;
				*( float* )( params + 20 ) = DamageScaleWithoutNewPlayerAssist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DamageScaleWithoutNewPlayerAssist = *( float* )( params + 20 );
				return *( float* )( params + function->return_val_offset() );
			}

			void DoRepairs( int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.DoRepairs" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = HealAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( class Actor** )( params + 8 ) = DamageCauser;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Controller* CheckTribesTurretInstigator( class Controller* EventInstigator, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CheckTribesTurretInstigator" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = EventInstigator;
				*( class Actor** )( params + 4 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayWhiteoutEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayWhiteoutEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeRadiusDamage( class Controller* EventInstigator, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.TakeRadiusDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Controller** )( params + 0 ) = EventInstigator;
				*( float* )( params + 4 ) = BaseDamage;
				*( float* )( params + 8 ) = DamageRadius;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HurtOrigin;
				*( bool* )( params + 32 ) = bFullDamage;
				*( class Actor** )( params + 36 ) = DamageCauser;
				*( float* )( params + 40 ) = DamageFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RecentlyGrabbedFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.RecentlyGrabbedFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetShowDistanceThreshold( bool bIsEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetShowDistanceThreshold" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bIsEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void Landed( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.Landed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeFallingDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.TakeFallingDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayHardLandingEffect( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayHardLandingEffect" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySonicPunchEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlaySonicPunchEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeFallDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.TakeFallDamage" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessCreditEvent( byte EventType, bool bProxyEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ProcessCreditEvent" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = EventType;
				*( bool* )( params + 4 ) = bProxyEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlashLocationUpdated( class Weapon* InWeapon, Vector InFlashLocation, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.FlashLocationUpdated" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( Vector* )( params + 4 ) = InFlashLocation;
				*( bool* )( params + 16 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponFired( class Weapon* InWeapon, bool bViaReplication, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.WeaponFired" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Dodge( byte DoubleClickMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.Dodge" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = DoubleClickMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PerformDodge( byte DoubleClickMove, Vector Dir, Vector Cross )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PerformDodge" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )( params + 0 ) = DoubleClickMove;
				*( Vector* )( params + 4 ) = Dir;
				*( Vector* )( params + 16 ) = Cross;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void gibbedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.gibbedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldGib( ScriptClass* UTDamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ShouldGib" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = UTDamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetHandIKEnabled( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetHandIKEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDamageCameraShake(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayDamageCameraShake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsLastHitFromNinjaSmoke(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.IsLastHitFromNinjaSmoke" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayTakeHitEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayTakeHitEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopLocalEffectsAndSounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StopLocalEffectsAndSounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOverlayMeshHidden( bool bNewHidden )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetOverlayMeshHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewHidden;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDying( ScriptClass* DamageType, Vector HitLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayDying" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = DamageType;
				*( Vector* )( params + 4 ) = HitLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTeamChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.NotifyTeamChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTeamBlockerMaterials(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.UpdateTeamBlockerMaterials" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PossessedBy( class Controller* C, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PossessedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = C;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetSkin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ResetSkin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkin( class Material* NewMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Material** )( params + 0 ) = NewMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeOverlayMaterials(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.InitializeOverlayMaterials" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayHealthRegenEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClientPlayHealthRegenEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShieldPackActive( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetShieldPackActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayShieldPackEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayShieldPackEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetStealthPackActive( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetStealthPackActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayStealthPackEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayStealthPackEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PulseStealth( bool bOverrideIgnore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PulseStealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bOverrideIgnore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRagePerkActive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetRagePerkActive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRagePerk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClearRagePerk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRageEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayRageEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayInvulnerabilityEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayInvulnerabilityEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartRidingInVehicle( class TrVehicle* V, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StartRidingInVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrVehicle** )( params + 0 ) = V;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopRidingInVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StopRidingInVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartDriving( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StartDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopDriving( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StopDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRanOver( class SVehicle* Vehicle, int WheelIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnRanOver" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SVehicle** )( params + 0 ) = Vehicle;
				*( int* )( params + 8 ) = WheelIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableJamming(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.EnableJamming" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableJamming(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.DisableJamming" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableJammingOtherPawns(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.DisableJammingOtherPawns" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnteredFriendJammingRadius( class TrPawn* JammingFriend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.EnteredFriendJammingRadius" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )( params + 0 ) = JammingFriend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExitFriendJammingRadius( class TrPawn* JammingFriend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ExitFriendJammingRadius" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )( params + 0 ) = JammingFriend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnteredEnemyJammingRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.EnteredEnemyJammingRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExitEnemyJammingRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ExitEnemyJammingRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsJammedByEnemy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.IsJammedByEnemy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayJammerPackEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayJammerPackEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayJammingByFriendEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayJammingByFriendEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayEnemyJammerPackEffect( bool enteredJammingRadius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayEnemyJammerPackEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = enteredJammingRadius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPawnDetectedByCollisionProxy( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnPawnDetectedByCollisionProxy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPawnExitedCollisionProxy( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnPawnExitedCollisionProxy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnEnteredDropJammer( class TrDeployable_DropJammer* DropJammer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnEnteredDropJammer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDeployable_DropJammer** )( params + 0 ) = DropJammer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnExitedDropJammer( class TrDeployable_DropJammer* DropJammer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnExitedDropJammer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDeployable_DropJammer** )( params + 0 ) = DropJammer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateEnemyDropJammer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.UpdateEnemyDropJammer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateFriendlyDropJammer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.UpdateFriendlyDropJammer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayJammingByEnemyDropJammerEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayJammingByEnemyDropJammerEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayJammingByFriendlyDropJammerEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayJammingByFriendlyDropJammerEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnChangeJammingTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnChangeJammingTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMeshVisibility( bool bVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetMeshVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFirstPersonBodyVisibility( bool bHide )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetFirstPersonBodyVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bHide;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponAttachmentChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.WeaponAttachmentChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceCrouch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ForceCrouch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindClosestStickyGrenadeSocketIndex( Vector ProjectileLocation, bool bOnlyFindAvailableSlots )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.FindClosestStickyGrenadeSocketIndex" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = ProjectileLocation;
				*( bool* )( params + 12 ) = bOnlyFindAvailableSlots;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void StickGrenadeToPawn( class TrProjectile* Projectile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StickGrenadeToPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrProjectile** )( params + 0 ) = Projectile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateStickyGrenades( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.UpdateStickyGrenades" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkiing( bool bEnabled, bool bJump )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetSkiing" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bEnabled;
				*( bool* )( params + 4 ) = bJump;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySkiEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlaySkiEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopSkiEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StopSkiEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySkiEffectsSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlaySkiEffectsSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopSkiEffectsSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StopSkiEffectsSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FaceRotation( Rotator NewRotation, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.FaceRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				*( float* )( params + 12 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDyingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayDyingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HoldGameObject( class UDKCarriedObject* GameObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.HoldGameObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKCarriedObject** )( params + 0 ) = GameObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustDamage( int &InDamage, Vector &Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.AdjustDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = InDamage;
				*( Vector* )( params + 4 ) = Momentum;
				*( class Controller** )( params + 16 ) = InstigatedBy;
				*( Vector* )( params + 20 ) = HitLocation;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InDamage = *( int* )( params + 0 );
				Momentum = *( Vector* )( params + 4 );
			}

			void GoInvulnerable( float InvulnerableTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GoInvulnerable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = InvulnerableTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearInvulnerability(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClearInvulnerability" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovementPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetMovementPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimEnd( class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.OnAnimEnd" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AnimNodeSequence** )( params + 0 ) = SeqNode;
				*( float* )( params + 4 ) = PlayedTime;
				*( float* )( params + 8 ) = ExcessTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayTeleportEffect( bool bOut, bool bSound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayTeleportEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bOut;
				*( bool* )( params + 4 ) = bSound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TurnOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.TurnOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDetectedByEnemyScanner( bool detected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetDetectedByEnemyScanner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = detected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetDetectedByEnemyScanner(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetDetectedByEnemyScanner" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetScannerDetect( bool detected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetScannerDetect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = detected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptClass* GetFamilyInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetFamilyInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void LockedOutFromFlagPickupTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.LockedOutFromFlagPickupTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LockFromFlagPickup( float TimeToLock )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.LockFromFlagPickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = TimeToLock;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Blink( Vector Impulse, float MinZ, float PctEffectiveness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.Blink" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = Impulse;
				*( float* )( params + 12 ) = MinZ;
				*( float* )( params + 16 ) = PctEffectiveness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayBlinkPackEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.PlayBlinkPackEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DoJump( bool bUpdating )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.DoJump" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bUpdating;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckClotheslineDamage( class Pawn* PawnHittingMe )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CheckClotheslineDamage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = PawnHittingMe;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSpectatorName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.GetSpectatorName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void CrushedBy( class Pawn* OtherPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CrushedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = OtherPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StuckOnPawn( class Pawn* OtherPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.StuckOnPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = OtherPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPending3PSkin( ScriptClass* NewPendingSkin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.SetPending3PSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = NewPendingSkin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckApplyPending3PSkin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.CheckApplyPending3PSkin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThrowActiveWeapon( bool bDestroyWeap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ThrowActiveWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bDestroyWeap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThrowWeaponOnDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ThrowWeaponOnDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSkiParticleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClearSkiParticleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJetpackParticleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.ClearJetpackParticleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AlienFXOverlay( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPawn.AlienFXOverlay" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
