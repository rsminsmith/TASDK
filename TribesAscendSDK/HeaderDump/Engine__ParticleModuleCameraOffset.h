#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleCameraOffset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleCameraOffset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleCameraOffset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleCameraOffset : public ParticleModuleCameraBase
	{
	public:
			ADD_VAR( ::ByteProperty, UpdateMethod, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSpawnTimeOnly, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
