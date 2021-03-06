/*******************************************************
Copyright (C) 2014 Nikolay & Gabriele-V

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
********************************************************/

#ifndef MM_EX_MMSIMPLEDIALOGS_H_
#define MM_EX_MMSIMPLEDIALOGS_H_

#include "mmex.h"

#include "model/Model_Account.h"

class mmSingleChoiceDialog : public wxSingleChoiceDialog
{
public:
    using wxSingleChoiceDialog::ShowModal;

    mmSingleChoiceDialog();
    mmSingleChoiceDialog(wxWindow *parent, const wxString& message,
        const wxString& caption, const wxArrayString& choices);
    mmSingleChoiceDialog(wxWindow* parent, const wxString& message,
        const wxString& caption, const Model_Account::Data_Set& accounts);
    int ShowModal()
    {
        return wxSingleChoiceDialog::ShowModal();
    }
};

class mmMultiChoiceDialog : public wxMultiChoiceDialog
{
public:
    using wxMultiChoiceDialog::ShowModal;

    mmMultiChoiceDialog();
    mmMultiChoiceDialog(wxWindow* parent, const wxString& message,
        const wxString& caption, const Model_Account::Data_Set& accounts);
    int ShowModal()
    {
        return wxMultiChoiceDialog::ShowModal();
    }
};

class mmDialogComboBoxAutocomplete : public wxDialog
{
public:
    mmDialogComboBoxAutocomplete();
    mmDialogComboBoxAutocomplete(wxWindow *parent, const wxString& message, const wxString& caption,
        const wxString& defaultText, const wxArrayString& choices);

    wxString getText()
    {
        return cbText_->GetValue();
    };

private:
    bool Create(wxWindow* parent, wxWindowID id,
        const wxString& caption, const wxPoint& pos, const wxSize& size, long style);
    wxString Message, Default;
    wxArrayString Choices;
    wxComboBox* cbText_;
};

class mmErrorDialogs
{
public:
    static void MessageInvalid(wxWindow *parent, const wxString &message);
    static void MessageError(wxWindow *parent, const wxString &message, const wxString &title);
    static void MessageWarning(wxWindow *parent, const wxString &message, const wxString &title);
    static void InvalidCategory(wxWindow *button, bool simple = true);
    static void InvalidAccount(wxWindow *object, bool transfer = false);
    static void InvalidFile(wxWindow *object, bool open = false);
    static void InvalidPayee(wxWindow *object);
    static void InvalidName(wxTextCtrl *textBox, bool alreadyexist = false);
    static void InvalidSymbol(wxTextCtrl *textBox, bool alreadyexist = false);
    static void ToolTip4Object(wxWindow *object, const wxString &message, const wxString &title, int ico = wxICON_WARNING);
};
#endif // MM_EX_MMSIMPLEDIALOGS_H_
