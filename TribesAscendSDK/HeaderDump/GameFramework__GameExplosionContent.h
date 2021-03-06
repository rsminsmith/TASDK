#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameExplosionContent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameExplosionContent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameExplosionContent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameExplosionContent : public Object
	{
	public:
			ADD_OBJECT( FogVolumeSphericalDensityInfo, FogVolumeArchetype )
			ADD_OBJECT( ParticleSystem, ParticleEmitterTemplate )
			ADD_VAR( ::FloatProperty, ExploRadialBlurMaxBlur, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExploRadialBlurFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExploLightFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraLensEffectRadius, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, CameraLensEffect )
			ADD_VAR( ::FloatProperty, CamShakeFalloff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamShakeOuterRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamShakeInnerRadius, 0xFFFFFFFF )
			ADD_OBJECT( CameraShake, CamShake_Rear )
			ADD_OBJECT( CameraShake, CamShake_Right )
			ADD_OBJECT( CameraShake, CamShake_Left )
			ADD_OBJECT( CameraShake, CamShake )
			ADD_OBJECT( SoundCue, ExplosionSound )
			ADD_VAR( ::BoolProperty, bOrientCameraShakeTowardsEpicenter, 0x2 )
			ADD_VAR( ::BoolProperty, bAutoControllerVibration, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
