#-*- coding:utf-8 -*-
src_path = "base/win32"

import codecs
import os


def change(src_path):
	for root,_,files in os.walk(src_path):
		for fname in files:
			fpath = os.path.join(root,fname)
			new_s = ""
			with open(fpath,"rb") as f:
				s = f.read()
				if s.startswith(codecs.BOM_UTF8):
					print "has with bom:%s"%fpath
					continue
				new_s = codecs.BOM_UTF8 + s
			if new_s:
				with open(fpath,"wb") as f:
					f.write(new_s)
					print "change to bom:%s"%fpath
				new_s = ""


if __name__=="__main__":
	change(src_path)