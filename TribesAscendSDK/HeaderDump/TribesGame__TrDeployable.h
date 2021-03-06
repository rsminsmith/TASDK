#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable : public TrGameObjective
	{
	public:
			ADD_OBJECT( Controller, m_Controller )
			ADD_VAR( ::IntProperty, m_nIconStackId, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, r_OwnerPRI )
			ADD_VAR( ::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeScalePlayRate, m_AnimNodeScale )
			ADD_OBJECT( Actor, m_LastViewer )
			ADD_OBJECT( PlayerController, m_LastRealViewer )
			ADD_VAR( ::FloatProperty, m_fNetRelevancyTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_DeploySound )
			ADD_OBJECT( TrPowerGenerator, m_MyMainGenerator )
			ADD_OBJECT( Pawn, r_TargetPawn )
			ADD_VAR( ::ByteProperty, r_FlashCount, 0xFFFFFFFF )
			ADD_OBJECT( TrSubDevice, m_Weapon )
			ADD_OBJECT( TrTurretPawn, m_WeaponHolder )
			ADD_OBJECT( ScriptClass, m_DeviceClass )
			ADD_VAR( ::FloatProperty, m_fAlwaysRelevantDistanceSquared, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fNewDetectionRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageRadius, 0xFFFFFFFF )
			ADD_OBJECT( TrDeployableCollisionProxy, m_CollisionProxy )
			ADD_VAR( ::FloatProperty, m_fOverriddenTargetComponentHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_TargetCollisionTraceDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFiringArcCheckValue, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_PlacementOrientationVector, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nFiringArcDegrees, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bBlocksFriendlies, 0x80 )
			ADD_VAR( ::BoolProperty, m_bCanBeSpottedByVGS, 0x40 )
			ADD_VAR( ::BoolProperty, m_bIsXRay, 0x20 )
			ADD_VAR( ::BoolProperty, m_bCachedRelevant, 0x10 )
			ADD_VAR( ::BoolProperty, m_bOverrideTargetComponentHeight, 0x8 )
			ADD_VAR( ::BoolProperty, m_bUsesArmoredMultiplier, 0x4 )
			ADD_VAR( ::BoolProperty, m_bRequireLOS, 0x2 )
			ADD_VAR( ::BoolProperty, m_bIsDeployed, 0x1 )
			ADD_VAR( ::FloatProperty, m_fTimeToDeploySecs, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemoteActivationTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBuildupTime, 0xFFFFFFFF )
			ADD_OBJECT( TrPawn, m_TouchedPlayer )
			ADD_VAR( ::FloatProperty, m_TimeCreated, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxDeployablesOut, 0xFFFFFFFF )
			void AdjustMeshToGround(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.AdjustMeshToGround" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float CalcMeshOffset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.CalcMeshOffset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool IsInLOS( class Actor* TouchedActor, Vector StartLocation, Vector EndLocation, bool CheckBlockedByBlockers, bool CheckBlockedByActors )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.IsInLOS" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Actor** )( params + 0 ) = TouchedActor;
				*( Vector* )( params + 4 ) = StartLocation;
				*( Vector* )( params + 16 ) = EndLocation;
				*( bool* )( params + 28 ) = CheckBlockedByBlockers;
				*( bool* )( params + 32 ) = CheckBlockedByActors;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPRIReplicated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnPRIReplicated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.TakeRadiusDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Controller** )( params + 0 ) = InstigatedBy;
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

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.TakeDamage" );
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

			void OnPawnDetectedByCollisionProxy( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnPawnDetectedByCollisionProxy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPawnExitedCollisionProxy( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnPawnExitedCollisionProxy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnVehicleDetectedByCollisionProxy( class TrVehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnVehicleDetectedByCollisionProxy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnVehicleExitedCollisionProxy( class TrVehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnVehicleExitedCollisionProxy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPowerStatusChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnPowerStatusChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInstigatorController( class TrPlayerController* InstigatorController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.SetInstigatorController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )( params + 0 ) = InstigatorController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetDamageRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.GetDamageRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void FinalizeDeployment(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.FinalizeDeployment" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeployComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.DeployComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.IsFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateHealthMaterial(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.UpdateHealthMaterial" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnHealthChanged( bool wasDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnHealthChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = wasDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetWeaponStartTraceLocation( class Weapon* CurrentWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.GetWeaponStartTraceLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = CurrentWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool StopsProjectile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.StopsProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void IncrementFlashCount( class Weapon* W, byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.IncrementFlashCount" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )( params + 0 ) = W;
				*( byte* )( params + 4 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireEffects( class Weapon* InWeapon, bool bViaReplication, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.PlayFireEffects" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PulseBackupGenerators(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.PulseBackupGenerators" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReceivesPowerFromGenerator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.ReceivesPowerFromGenerator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetPossessiveInstigatorName( ScriptArray< wchar_t > &PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.GetPossessiveInstigatorName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlayerName = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CalcOtherWatchingCam( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV, class TrPlayerController* WatcherController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.CalcOtherWatchingCam" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( float* )( params + 0 ) = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				*( class TrPlayerController** )( params + 32 ) = WatcherController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnUpgradePerformed( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable.OnUpgradePerformed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
