//---------------------------------------------------------------------------
/**
 * ���C���[�c���[��ێ�����@�\�� Window�݂̂łȂ��A��ʉ����A���̃C���^�[�t�F�C�X
 * �����N���X�ł���΁A���C���[�c���[�����Ă�悤�ɂ���
 * 
 */
//---------------------------------------------------------------------------
//!@file ���C���[�c���[�I�[�i�[
//---------------------------------------------------------------------------
#ifndef LayerTreeOwner_H
#define LayerTreeOwner_H


class iTVPLayerTreeOwner
{
public:
	// LayerManager/Layer -> LTO
	virtual void TJS_INTF_METHOD RegisterLayerManager( class iTVPLayerManager* manager ) = 0;
	virtual void TJS_INTF_METHOD UnregisterLayerManager( class iTVPLayerManager* manager ) = 0;

	virtual void TJS_INTF_METHOD StartBitmapCompletion(iTVPLayerManager * manager) = 0;
	virtual void TJS_INTF_METHOD NotifyBitmapCompleted(class iTVPLayerManager * manager,
		tjs_int x, tjs_int y, const void * bits, const class BitmapInfomation * bitmapinfo,
		const tTVPRect &cliprect, tTVPLayerType type, tjs_int opacity) = 0;
	virtual void TJS_INTF_METHOD EndBitmapCompletion(iTVPLayerManager * manager) = 0;

	virtual void TJS_INTF_METHOD SetMouseCursor(class iTVPLayerManager* manager, tjs_int cursor) = 0;
	virtual void TJS_INTF_METHOD GetCursorPos(class iTVPLayerManager* manager, tjs_int &x, tjs_int &y) = 0;
	virtual void TJS_INTF_METHOD SetCursorPos(class iTVPLayerManager* manager, tjs_int x, tjs_int y) = 0;
	virtual void TJS_INTF_METHOD ReleaseMouseCapture(class iTVPLayerManager* manager) = 0;

	virtual void TJS_INTF_METHOD SetHint(class iTVPLayerManager* manager, iTJSDispatch2* sender, const ttstr &hint) = 0;

	virtual void TJS_INTF_METHOD NotifyLayerResize(class iTVPLayerManager* manager) = 0;
	virtual void TJS_INTF_METHOD NotifyLayerImageChange(class iTVPLayerManager* manager) = 0;

	virtual void TJS_INTF_METHOD SetAttentionPoint(class iTVPLayerManager* manager, tTJSNI_BaseLayer *layer, tjs_int x, tjs_int y) = 0;
	virtual void TJS_INTF_METHOD DisableAttentionPoint(class iTVPLayerManager* manager) = 0;

	virtual void TJS_INTF_METHOD SetImeMode( class iTVPLayerManager* manager, tjs_int mode ) = 0; // mode == tTVPImeMode
	virtual void TJS_INTF_METHOD ResetImeMode( class iTVPLayerManager* manager ) = 0;

	virtual iTJSDispatch2 * TJS_INTF_METHOD GetOwnerNoAddRef() const = 0;
	// LTO -> LayerManager/Layer
	// LTO ����̒ʒm�͕K�v�v���ł͂Ȃ�
};

#endif