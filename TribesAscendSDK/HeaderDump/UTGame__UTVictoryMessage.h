#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTVictoryMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTVictoryMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTVictoryMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVictoryMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundNodeWave, VictorySounds )
			byte AnnouncementLevel( byte MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVictoryMessage.AnnouncementLevel" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			class SoundNodeWave* AnnouncementSound( int MessageIndex, class Object* OptionalObject, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVictoryMessage.AnnouncementSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = MessageIndex;
				*( class Object** )( params + 4 ) = OptionalObject;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVictoryMessage.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AddAnnouncement( class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVictoryMessage.AddAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTAnnouncer** )( params + 0 ) = Announcer;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
