#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.K2Connector." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.K2Connector." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.K2Connector." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class K2Connector : public Object
	{
	public:
			ADD_VAR( ::ByteProperty, Type, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ConnName, 0xFFFFFFFF )
			ADD_OBJECT( K2NodeBase, OwningNode )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
