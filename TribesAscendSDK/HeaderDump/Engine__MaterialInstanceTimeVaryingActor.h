#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MaterialInstanceTimeVaryingActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MaterialInstanceTimeVaryingActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MaterialInstanceTimeVaryingActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialInstanceTimeVaryingActor : public Actor
	{
	public:
			ADD_OBJECT( MaterialInstanceTimeVarying, MatInst )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
