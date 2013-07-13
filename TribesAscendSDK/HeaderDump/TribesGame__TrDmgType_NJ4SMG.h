#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDmgType_NJ4SMG." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDmgType_NJ4SMG." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDmgType_NJ4SMG." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDmgType_NJ4SMG : public TrDmgType_Bullet
	{
	public:
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
