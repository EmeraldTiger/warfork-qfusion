/*
Copyright (C) 2014 SiPlus, Chasseur de bots

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include <dlfcn.h>
#include "android_sys.h"
#include "../qcommon/sys_library.h"

/*
* Sys_Library_Close
*/
bool Sys_Library_Close( void *lib )
{
	return dlclose( lib ) ? false : true;
}

/*
* Sys_Library_GetFullName
*/
const char *Sys_Library_GetFullName( const char *name )
{
	static char tempname[PATH_MAX];
	Q_snprintfz( tempname, sizeof( tempname ), "%s/lib/%s", sys_android_internalDataPath, COM_FileBase( name ) );
	return tempname;
}

/*
* Sys_Library_Open
*/
void *Sys_Library_Open( const char *name )
{
	return dlopen( name, RTLD_NOW );
}

/*
* Sys_Library_ProcAddress
*/
void *Sys_Library_ProcAddress( void *lib, const char *apifuncname )
{
	return dlsym( lib, apifuncname );
}

/*
* Sys_Library_ErrorString
*/
const char *Sys_Library_ErrorString( void )
{
	return dlerror();
}

