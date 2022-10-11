#!/usr/bin/sh

g++ -Wall -pedantic-errors `wx-config --cxxflags` -o sos src/*.cc -Iinclude `wx-config --libs` "$@"

#g++ -I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -pthread -o sos src/*.cc -Iinclude -pthread -lwx_gtk3u_xrc-3.2 -lwx_gtk3u_html-3.2 -lwx_gtk3u_qa-3.2 -lwx_gtk3u_core-3.2 -lwx_baseu_xml-3.2 -lwx_baseu_net-3.2 -lwx_baseu-3.2 

