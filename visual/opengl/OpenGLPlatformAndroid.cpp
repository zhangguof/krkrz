
#include "tjsCommHead.h"
#include "DebugIntf.h"
#include "Application.h"
#include "FilePathUtil.h"
#include "MsgIntf.h"	// TVPThrowExceptionMessage
#include "SysInitIntf.h"

#include "OpenGLHeader.h"


//---------------------------------------------------------------------------
static bool TVPANGLEInit = false;
static bool TVPIsSupportES3 = false;
static int TVPOpenGLESVersion = 100;
//---------------------------------------------------------------------------
void TVPInitializeOpenGLPlatform() {
	if( TVPANGLEInit == false ) {
		TVPOpenGLESVersion = Application->GetOpenGLESVersionCode();
		if( TVPOpenGLESVersion >= 300 ) {
			if( gl3stubInit() == GL_TRUE ) {
				TVPIsSupportES3 = true;
			}
		}
		TVPANGLEInit = true;
	}
}
//---------------------------------------------------------------------------
int TVPGetOpenGLESVersion() { return TVPOpenGLESVersion; }
//---------------------------------------------------------------------------