#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SceneCaptureReflectComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SceneCaptureReflectComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SceneCaptureReflectComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCaptureReflectComponent : public SceneCaptureComponent
	{
	public:
			ADD_VAR( ::FloatProperty, ScaleFOV, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTarget2D, TextureTarget )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
