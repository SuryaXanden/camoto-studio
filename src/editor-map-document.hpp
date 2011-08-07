/**
 * @file   editor-map-document.hpp
 * @brief  Map editor document.
 *
 * Copyright (C) 2010-2011 Adam Nielsen <malvineous@shikadi.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _EDITOR_MAP_DOCUMENT_HPP_
#define _EDITOR_MAP_DOCUMENT_HPP_

#include <camoto/gamemaps.hpp>
#include <camoto/gamegraphics.hpp>

class MapDocument;

#include "editor.hpp"
#include "editor-map-canvas.hpp"

class LayerPanel;

class MapDocument: public IDocument
{
	public:
		MapDocument(IMainWindow *parent, camoto::gamemaps::Map2DPtr map,
			camoto::gamegraphics::VC_TILESET tileset)
			throw ();

		void onZoomSmall(wxCommandEvent& ev);

		void onZoomNormal(wxCommandEvent& ev);

		void onZoomLarge(wxCommandEvent& ev);

		void onToggleGrid(wxCommandEvent& ev);

		void setStatusText(const wxString& text);

	protected:
		MapCanvas *canvas;
		camoto::gamemaps::Map2DPtr map;
		camoto::gamegraphics::VC_TILESET tileset;

		friend class LayerPanel;

		enum {
			IDC_TOGGLEGRID = wxID_HIGHEST + 1,
		};
		DECLARE_EVENT_TABLE();
};

#endif // _EDITOR_MAP_DOCUMENT_HPP_
