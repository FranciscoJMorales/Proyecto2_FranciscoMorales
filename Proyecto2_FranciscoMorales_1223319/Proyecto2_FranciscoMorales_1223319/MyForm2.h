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

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(Usuario^ user, DateTime^ fecha)
		{
			InitializeComponent();
			usuario = user;
			FormClosing += gcnew FormClosingEventHandler(this, &MyForm2::OnClosing);
			fechaLbl->Text = "Fecha: " + fecha->ToString("dd/MM/yyyy");
			fechaInicio = gcnew DateTime(fecha->Year, fecha->Month, fecha->Day);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  fechaLbl;
	protected:

	private: System::Windows::Forms::RadioButton^  actividadRbtn;
	private: System::Windows::Forms::RadioButton^  recordatorioRbtn;
	private: System::Windows::Forms::RadioButton^  alarmaRbtn;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  descripcionTbx;
	private: System::Windows::Forms::TextBox^  prioridadTbx;
	private: System::Windows::Forms::TextBox^  inicioTbx;
	private: System::Windows::Forms::TextBox^  finTbx;
	private: System::Windows::Forms::TextBox^  personasTbx;
	private: System::Windows::Forms::TextBox^  lugarTbx;
	private: System::Windows::Forms::TextBox^  materialesTbx;
	private: System::Windows::Forms::Button^  agregarBtn;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fechaLbl = (gcnew System::Windows::Forms::Label());
			this->actividadRbtn = (gcnew System::Windows::Forms::RadioButton());
			this->recordatorioRbtn = (gcnew System::Windows::Forms::RadioButton());
			this->alarmaRbtn = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->descripcionTbx = (gcnew System::Windows::Forms::TextBox());
			this->prioridadTbx = (gcnew System::Windows::Forms::TextBox());
			this->inicioTbx = (gcnew System::Windows::Forms::TextBox());
			this->finTbx = (gcnew System::Windows::Forms::TextBox());
			this->personasTbx = (gcnew System::Windows::Forms::TextBox());
			this->lugarTbx = (gcnew System::Windows::Forms::TextBox());
			this->materialesTbx = (gcnew System::Windows::Forms::TextBox());
			this->agregarBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tipo:";
			// 
			// fechaLbl
			// 
			this->fechaLbl->AutoSize = true;
			this->fechaLbl->Location = System::Drawing::Point(48, 96);
			this->fechaLbl->Name = L"fechaLbl";
			this->fechaLbl->Size = System::Drawing::Size(40, 13);
			this->fechaLbl->TabIndex = 1;
			this->fechaLbl->Text = L"Fecha:";
			// 
			// actividadRbtn
			// 
			this->actividadRbtn->AutoSize = true;
			this->actividadRbtn->Checked = true;
			this->actividadRbtn->Location = System::Drawing::Point(94, 17);
			this->actividadRbtn->Name = L"actividadRbtn";
			this->actividadRbtn->Size = System::Drawing::Size(69, 17);
			this->actividadRbtn->TabIndex = 2;
			this->actividadRbtn->TabStop = true;
			this->actividadRbtn->Text = L"Actividad";
			this->actividadRbtn->UseVisualStyleBackColor = true;
			this->actividadRbtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm2::actividadRbtn_CheckedChanged);
			// 
			// recordatorioRbtn
			// 
			this->recordatorioRbtn->AutoSize = true;
			this->recordatorioRbtn->Location = System::Drawing::Point(94, 40);
			this->recordatorioRbtn->Name = L"recordatorioRbtn";
			this->recordatorioRbtn->Size = System::Drawing::Size(86, 17);
			this->recordatorioRbtn->TabIndex = 3;
			this->recordatorioRbtn->Text = L"Recordatorio";
			this->recordatorioRbtn->UseVisualStyleBackColor = true;
			this->recordatorioRbtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm2::recordatorioRbtn_CheckedChanged);
			// 
			// alarmaRbtn
			// 
			this->alarmaRbtn->AutoSize = true;
			this->alarmaRbtn->Location = System::Drawing::Point(94, 63);
			this->alarmaRbtn->Name = L"alarmaRbtn";
			this->alarmaRbtn->Size = System::Drawing::Size(57, 17);
			this->alarmaRbtn->TabIndex = 4;
			this->alarmaRbtn->Text = L"Alarma";
			this->alarmaRbtn->UseVisualStyleBackColor = true;
			this->alarmaRbtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm2::alarmaRbtn_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Descripción:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Hora de inicio:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(37, 159);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Prioridad:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(34, 237);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Personas:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(51, 263);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Lugar:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(26, 211);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(62, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Hora de fin:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(30, 289);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 13);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Materiales:";
			// 
			// descripcionTbx
			// 
			this->descripcionTbx->Location = System::Drawing::Point(94, 130);
			this->descripcionTbx->Name = L"descripcionTbx";
			this->descripcionTbx->Size = System::Drawing::Size(100, 20);
			this->descripcionTbx->TabIndex = 12;
			// 
			// prioridadTbx
			// 
			this->prioridadTbx->Location = System::Drawing::Point(94, 156);
			this->prioridadTbx->Name = L"prioridadTbx";
			this->prioridadTbx->Size = System::Drawing::Size(100, 20);
			this->prioridadTbx->TabIndex = 13;
			// 
			// inicioTbx
			// 
			this->inicioTbx->Location = System::Drawing::Point(94, 182);
			this->inicioTbx->Name = L"inicioTbx";
			this->inicioTbx->Size = System::Drawing::Size(100, 20);
			this->inicioTbx->TabIndex = 14;
			// 
			// finTbx
			// 
			this->finTbx->Location = System::Drawing::Point(94, 208);
			this->finTbx->Name = L"finTbx";
			this->finTbx->Size = System::Drawing::Size(100, 20);
			this->finTbx->TabIndex = 15;
			// 
			// personasTbx
			// 
			this->personasTbx->Location = System::Drawing::Point(94, 234);
			this->personasTbx->Name = L"personasTbx";
			this->personasTbx->Size = System::Drawing::Size(100, 20);
			this->personasTbx->TabIndex = 16;
			// 
			// lugarTbx
			// 
			this->lugarTbx->Location = System::Drawing::Point(94, 260);
			this->lugarTbx->Name = L"lugarTbx";
			this->lugarTbx->Size = System::Drawing::Size(100, 20);
			this->lugarTbx->TabIndex = 17;
			// 
			// materialesTbx
			// 
			this->materialesTbx->Location = System::Drawing::Point(94, 286);
			this->materialesTbx->Name = L"materialesTbx";
			this->materialesTbx->Size = System::Drawing::Size(100, 20);
			this->materialesTbx->TabIndex = 18;
			// 
			// agregarBtn
			// 
			this->agregarBtn->Location = System::Drawing::Point(73, 326);
			this->agregarBtn->Name = L"agregarBtn";
			this->agregarBtn->Size = System::Drawing::Size(75, 23);
			this->agregarBtn->TabIndex = 19;
			this->agregarBtn->Text = L"Agregar";
			this->agregarBtn->UseVisualStyleBackColor = true;
			this->agregarBtn->Click += gcnew System::EventHandler(this, &MyForm2::agregarBtn_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(215, 370);
			this->Controls->Add(this->agregarBtn);
			this->Controls->Add(this->materialesTbx);
			this->Controls->Add(this->lugarTbx);
			this->Controls->Add(this->personasTbx);
			this->Controls->Add(this->finTbx);
			this->Controls->Add(this->inicioTbx);
			this->Controls->Add(this->prioridadTbx);
			this->Controls->Add(this->descripcionTbx);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->alarmaRbtn);
			this->Controls->Add(this->recordatorioRbtn);
			this->Controls->Add(this->actividadRbtn);
			this->Controls->Add(this->fechaLbl);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm2";
			this->Text = L"Nueva Tarea";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		Usuario^ usuario;
		DateTime^ fechaInicio;

	private: System::Void actividadRbtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		ChangeEnabled();
	}

	private: System::Void recordatorioRbtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		ChangeEnabled();
	}

	private: System::Void alarmaRbtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		ChangeEnabled();
	}

			 //Habilita o deshabilita los datos que son únicamente de las actividades
	private: System::Void ChangeEnabled() {
		if (actividadRbtn->Checked) {
			finTbx->Enabled = true;
			personasTbx->Enabled = true;
			lugarTbx->Enabled = true;
			materialesTbx->Enabled = true;
		}
		else {
			finTbx->Enabled = false;
			personasTbx->Enabled = false;
			lugarTbx->Enabled = false;
			materialesTbx->Enabled = false;
		}
	}

			 //Agrega la tarea nueva a la lista de tareas del usuario
	private: System::Void agregarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			Evento *nuevo = nullptr;
			String^ temp = inicioTbx->Text;
			fechaInicio = fechaInicio->AddHours(Convert::ToInt32(temp->Substring(0, temp->IndexOf(":"))));
			temp = temp->Remove(0, temp->IndexOf(":") + 1);
			fechaInicio = fechaInicio->AddMinutes(Convert::ToInt32(temp));
			if (actividadRbtn->Checked) {
				temp = finTbx->Text;
				int horaFin = Convert::ToInt32(temp->Substring(0, temp->IndexOf(":")));
				temp = temp->Remove(0, temp->IndexOf(":") + 1);
				int minutosFin = Convert::ToInt32(temp);
				temp = personasTbx->Text;
				temp = temp->Replace(",", "-");
				nuevo = new Actividad(0, descripcionTbx->Text, fechaInicio, horaFin, minutosFin, Convert::ToInt32(prioridadTbx->Text), temp, lugarTbx->Text, materialesTbx->Text);
			}
			else if (recordatorioRbtn->Checked) {
				nuevo = new Recordatorio(0, descripcionTbx->Text, fechaInicio, Convert::ToInt32(prioridadTbx->Text));
			}
			else {
				nuevo = new Alarma(0, descripcionTbx->Text, fechaInicio, Convert::ToInt32(prioridadTbx->Text));
			}
			usuario->Agregar(nuevo);
			MessageBox::Show("La tarea fue agregada exitosamente", "Tarea guardada");
			this->Close();
		}
		catch (...) {
			MessageBox::Show("Los datos no son válidos", "Error al crear tarea");
		}
	}

			 //Permite la utilización del formulario anterior
	private: System::Void OnClosing(System::Object^  sender, FormClosingEventArgs^  e) {
		this->Owner->Enabled = true;
	}
};
}
