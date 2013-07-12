#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrMusicManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrMusicManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrMusicManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrMusicManager : public Info
	{
	public:
			ADD_OBJECT( TrPlayerController, m_PlayerOwner )
			ADD_VAR( ::FloatProperty, m_fMusicVolume, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CurrentState, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_PendingState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fStingerVolumeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_CTFTeamScores, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT