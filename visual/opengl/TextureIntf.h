/**
 * Texture クラス
 */

#ifndef TextureIntfH
#define TextureIntfH

#include "tjsNative.h"
#include "GLTexture.h"

class tTJSNI_Texture : public tTJSNativeInstance
{
	GLTexture Texture;
	tjs_uint SrcWidth;
	tjs_uint SrcHeight;

	void LoadTexture( const class tTVPBaseBitmap* bitmap, bool alpha );

public:
	tTJSNI_Texture();
	~tTJSNI_Texture() override;
	tjs_error TJS_INTF_METHOD Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) override;
	void TJS_INTF_METHOD Invalidate() override;

	tjs_uint GetWidth() const { return SrcWidth; }
	tjs_uint GetHeight() const { return SrcHeight; }
	tjs_uint GetMemoryWidth() const { return Texture.width(); }
	tjs_uint GetMemoryHeight() const { return Texture.height(); }
	bool IsGray() const;
	bool IsPowerOfTwo() const;
	tjs_int64 GetNativeHandle() const { return Texture.id(); }

	static inline bool IsPowerOfTwo( tjs_uint x ) { return (x & (x - 1)) == 0; }
	static inline tjs_uint ToPowerOfTwo( tjs_uint x ) {
		// 組み込み関数等でMSBを取得してシフトしてもいいが、32からシフトしてループで得ることにする。
		if( IsPowerOfTwo( x ) == false ) {
			tjs_uint r = 32;
			while( r < x ) r = r << 1;
			return r;
		}
		return x;
	}
};


//---------------------------------------------------------------------------
// tTJSNC_Texture : TJS Texture class
//---------------------------------------------------------------------------
class tTJSNC_Texture : public tTJSNativeClass
{
public:
	tTJSNC_Texture();
	static tjs_uint32 ClassID;

protected:
	tTJSNativeInstance *CreateNativeInstance() override { return new tTJSNI_Texture(); }
};
//---------------------------------------------------------------------------
extern tTJSNativeClass * TVPCreateNativeClass_Texture();
#endif