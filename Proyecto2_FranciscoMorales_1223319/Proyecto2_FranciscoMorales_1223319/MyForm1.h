#pragma once
#include "Evento.h"
#include "Lista.h"
#include "Actividad.h"
#include "Recordatorio.h"
#include "Alarma.h"
#include "Usuario.h"
#include "MyForm2.h"

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
			MostrarTareas(DateTime::Now);
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  añoTbx;
	private: System::Windows::Forms::TextBox^  mesTbx;


	private: System::Windows::Forms::Button^  fechaBtn;
	private: System::Windows::Forms::Label^  tareasLbl;

	private: System::Windows::Forms::RichTextBox^  tareasTbx;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  agregarBtn;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->añoTbx = (gcnew System::Windows::Forms::TextBox());
			this->mesTbx = (gcnew System::Windows::Forms::TextBox());
			this->fechaBtn = (gcnew System::Windows::Forms::Button());
			this->tareasLbl = (gcnew System::Windows::Forms::Label());
			this->tareasTbx = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->agregarBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// calendario
			// 
			this->calendario->Location = System::Drawing::Point(18, 151);
			this->calendario->Name = L"calendario";
			this->calendario->TabIndex = 0;
			this->calendario->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &MyForm1::calendario_DateChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(260, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Agenda";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(47, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Año:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(46, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Mes:";
			// 
			// añoTbx
			// 
			this->añoTbx->Location = System::Drawing::Point(82, 42);
			this->añoTbx->Name = L"añoTbx";
			this->añoTbx->Size = System::Drawing::Size(100, 20);
			this->añoTbx->TabIndex = 4;
			// 
			// mesTbx
			// 
			this->mesTbx->Location = System::Drawing::Point(82, 71);
			this->mesTbx->Name = L"mesTbx";
			this->mesTbx->Size = System::Drawing::Size(100, 20);
			this->mesTbx->TabIndex = 5;
			// 
			// fechaBtn
			// 
			this->fechaBtn->Location = System::Drawing::Point(82, 97);
			this->fechaBtn->Name = L"fechaBtn";
			this->fechaBtn->Size = System::Drawing::Size(98, 23);
			this->fechaBtn->TabIndex = 6;
			this->fechaBtn->Text = L"Cambiar fecha";
			this->fechaBtn->UseVisualStyleBackColor = true;
			this->fechaBtn->Click += gcnew System::EventHandler(this, &MyForm1::fechaBtn_Click);
			// 
			// tareasLbl
			// 
			this->tareasLbl->AutoSize = true;
			this->tareasLbl->Location = System::Drawing::Point(305, 45);
			this->tareasLbl->Name = L"tareasLbl";
			this->tareasLbl->Size = System::Drawing::Size(43, 13);
			this->tareasLbl->TabIndex = 7;
			this->tareasLbl->Text = L"Tareas:";
			// 
			// tareasTbx
			// 
			this->tareasTbx->Location = System::Drawing::Point(294, 71);
			this->tareasTbx->Name = L"tareasTbx";
			this->tareasTbx->Size = System::Drawing::Size(304, 154);
			this->tareasTbx->TabIndex = 8;
			this->tareasTbx->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(291, 247);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(163, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Seleccione un día del calendario";
			// 
			// agregarBtn
			// 
			this->agregarBtn->Location = System::Drawing::Point(318, 274);
			this->agregarBtn->Name = L"agregarBtn";
			this->agregarBtn->Size = System::Drawing::Size(98, 23);
			this->agregarBtn->TabIndex = 10;
			this->agregarBtn->Text = L"Agregar tarea";
			this->agregarBtn->UseVisualStyleBackColor = true;
			this->agregarBtn->Click += gcnew System::EventHandler(this, &MyForm1::agregarBtn_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(610, 322);
			this->Controls->Add(this->agregarBtn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tareasTbx);
			this->Controls->Add(this->tareasLbl);
			this->Controls->Add(this->fechaBtn);
			this->Controls->Add(this->mesTbx);
			this->Controls->Add(this->añoTbx);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->calendario);
			this->Name = L"MyForm1";
			this->Text = L"Agenda";
			this->EnabledChanged += gcnew System::EventHandler(this, &MyForm1::MyForm1_EnabledChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		MyForm2^ formulario;
		Usuario^ persona;

	private: System::Void OnClosing(System::Object^  sender, FormClosingEventArgs^  e) {
		this->Owner->Show();
	}

	private: System::Void calendario_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {
		MostrarTareas(calendario->SelectionStart);
	}

	private: System::Void MostrarTareas(DateTime^ dia) {
		tareasLbl->Text = "Tareas " + dia->ToString("dd/MM/yyyy") + ":";
		tareasTbx->Text = persona->MostrarTareasDía(dia);
	}

	private: System::Void fechaBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			calendario->SelectionStart = Convert::ToDateTime(mesTbx->Text + "/" + añoTbx->Text);
		}
		catch (...) {
			MessageBox::Show("La fecha ingresada no es válida", "Error");
		}
	}

	private: System::Void agregarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		formulario = gcnew MyForm2(persona, calendario->SelectionStart);
		formulario->Show(this);
		this->Enabled = false;
	}

	private: System::Void MyForm1_EnabledChanged(System::Object^  sender, System::EventArgs^  e) {
		MostrarTareas(calendario->SelectionStart);
	}
};
}
