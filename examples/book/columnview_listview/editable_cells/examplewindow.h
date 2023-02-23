/* gtkmm example Copyright (C) 2023 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  ~ExampleWindow() override;

protected:
  // Signal handlers:
  void on_button_quit();
  void on_setup_id(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_setup_name(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_setup_foo(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_setup_number(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_setup_number_validated(const Glib::RefPtr<Gtk::ListItem>& list_item);

  void on_bind_id(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_name(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_foo(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_number(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_number_validated(const Glib::RefPtr<Gtk::ListItem>& list_item);

  void on_edited_id(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_edited_name(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_edited_foo(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_edited_number(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_edited_number_validated(const Glib::RefPtr<Gtk::ListItem>& list_item);

  // A Gio::ListStore item.
  class ModelColumns : public Glib::Object
  {
  public:
    unsigned int m_col_id;
    Glib::ustring m_col_name;
    bool m_col_foo;
    int m_col_number;
    int m_col_number_validated;

    static Glib::RefPtr<ModelColumns> create(unsigned int col_id,
      const Glib::ustring& col_name, bool col_foo, int col_number,
      int col_number_validated = 0)
    {
      return Glib::make_refptr_for_instance<ModelColumns>(
        new ModelColumns(col_id, col_name, col_foo, col_number, col_number_validated));
    }

  protected:
    ModelColumns(unsigned int col_id, const Glib::ustring& col_name,
      bool col_foo, int col_number, int col_number_validated)
    : m_col_id(col_id), m_col_name(col_name), m_col_foo(col_foo),
      m_col_number(col_number),m_col_number_validated(col_number_validated)
    {}
  }; // ModelColumns

  // Child widgets:
  Gtk::Box m_VBox;
  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::ColumnView m_ColumnView;
  Gtk::Box m_ButtonBox;
  Gtk::Button m_Button_Quit;

  Glib::RefPtr<Gio::ListStore<ModelColumns>> m_ListStore;
  Glib::RefPtr<Gtk::AlertDialog> m_AlertDialog;
};

#endif //GTKMM_EXAMPLEWINDOW_H
