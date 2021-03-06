/**
 * @file   dlg-export-mus.hpp
 * @brief  Dialog box for the preferences window.
 *
 * Copyright (C) 2010-2015 Adam Nielsen <malvineous@shikadi.net>
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

#ifndef _DLG_EXPORT_MUS_HPP_
#define _DLG_EXPORT_MUS_HPP_

#include <camoto/gamemusic/manager.hpp>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include "studio.hpp"

/// Export music file dialog box.
class DlgExportMusic: public wxDialog
{
	public:
		wxString filename;   ///< Name of file to write
		wxString fileType;   ///< File format to write as (libgamemusic format ID)
		unsigned int flags;  ///< libgamemusic export flags (MusicType::xxx)

		/// Initialise the dialog box.
		/**
		 * @param parent
		 *   Display the dialog within this window.
		 *
		 * @param pManager
		 *   libgamemusic manager interface, for retrieving the list of supported
		 *   file types.
		 */
		DlgExportMusic(Studio *parent, camoto::gamemusic::ManagerPtr pManager);

		~DlgExportMusic();

		/// Set the controls to show the values in the public variables.
		void setControls();

		/// Event handler for OK button.
		void onOK(wxCommandEvent& ev);

		/// Event handler for cancel/close button.
		void onCancel(wxCommandEvent& ev);

		/// Event handler for browse button.
		void onBrowse(wxCommandEvent& ev);

	protected:
		camoto::gamemusic::ManagerPtr pManager;

		wxTextCtrl *txtPath;
		wxComboBox *cbFileType;
		wxCheckBox *chkPitchBends;

		DECLARE_EVENT_TABLE();
};

#endif // _DLG_EXPORT_MUS_HPP_
