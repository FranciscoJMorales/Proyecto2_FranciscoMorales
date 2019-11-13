#pragma once
#include "Evento.h"
#include "Lista.h"
#include "Actividad.h"
#include "Recordatorio.h"
#include "Alarma.h"
#include "Usuario.h"

namespace Proyecto2_FranciscoMorales_1223319 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(String^ user)
		{
			InitializeComponent();
			FormClosing += gcnew FormClosingEventHandler(this, &MyForm1::OnClosing);
			persona = gcnew Usuario(user);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^  calendario;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->calendario = (gcnew System::Windows::Forms::MonthCalendar());
			this->SuspendLayout();
			// 
			// calendario
			// 
			this->calendario->Location = System::Drawing::Point(64, 114);
			this->calendario->Name = L"calendario";
			this->calendario->TabIndex = 0;
			this->calendario->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &MyForm1::calendario_DateChanged);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(462, 322);
			this->Controls->Add(this->calendario);
			this->Name = L"MyForm1";
			this->Text = L"Agenda";
			this->ResumeLayout(false);

		}
#pragma endregion
	
		Usuario^ persona;

	private: System::Void OnClosing(System::Object^  sender, FormClosingEventArgs^  e) {
		this->Owner->Show();
	}

	private: System::Void calendario_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {

	}

	private: System::Void CargarTareas() {
		StreamReader^ lector = gcnew StreamReader("..//" + persona->nombre + ".txt");
	}
};
}
