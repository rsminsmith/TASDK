#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleTypeDataTrail." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleTypeDataTrail." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleTypeDataTrail." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleTypeDataTrail : public ParticleModuleTypeDataBase
	{
	public:
			ADD_STRUCT( ::VectorProperty, SpawnDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TessellationFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, SpawnByDistance, 0x10 )
			ADD_VAR( ::BoolProperty, Tapered, 0x8 )
			ADD_VAR( ::BoolProperty, RenderTessellation, 0x4 )
			ADD_VAR( ::BoolProperty, RenderLines, 0x2 )
			ADD_VAR( ::BoolProperty, RenderGeometry, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
