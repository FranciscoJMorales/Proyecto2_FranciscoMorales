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
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  valorTbx;
	private: System::Windows::Forms::Button^  buscarBtn;
	private: System::Windows::Forms::Button^  ordenarBtn;
	private: System::Windows::Forms::RadioButton^  prioridadRbtn;
	private: System::Windows::Forms::RadioButton^  fechaRbtn;
	private: System::Windows::Forms::RadioButton^  idRbtn;

	private: System::Windows::Forms::Button^  exportarBtn;
	private: System::Windows::Forms::FolderBrowserDialog^  abrirCarpeta;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->valorTbx = (gcnew System::Windows::Forms::TextBox());
			this->buscarBtn = (gcnew System::Windows::Forms::Button());
			this->ordenarBtn = (gcnew System::Windows::Forms::Button());
			this->prioridadRbtn = (gcnew System::Windows::Forms::RadioButton());
			this->fechaRbtn = (gcnew System::Windows::Forms::RadioButton());
			this->idRbtn = (gcnew System::Windows::Forms::RadioButton());
			this->exportarBtn = (gcnew System::Windows::Forms::Button());
			this->abrirCarpeta = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->valorTbx);
			this->groupBox1->Controls->Add(this->buscarBtn);
			this->groupBox1->Controls->Add(this->ordenarBtn);
			this->groupBox1->Controls->Add(this->prioridadRbtn);
			this->groupBox1->Controls->Add(this->fechaRbtn);
			this->groupBox1->Controls->Add(this->idRbtn);
			this->groupBox1->Location = System::Drawing::Point(619, 29);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(142, 231);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ordenar o buscar por:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 147);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Valor por buscar:";
			// 
			// valorTbx
			// 
			this->valorTbx->Location = System::Drawing::Point(19, 163);
			this->valorTbx->Name = L"valorTbx";
			this->valorTbx->Size = System::Drawing::Size(100, 20);
			this->valorTbx->TabIndex = 12;
			// 
			// buscarBtn
			// 
			this->buscarBtn->Location = System::Drawing::Point(21, 189);
			this->buscarBtn->Name = L"buscarBtn";
			this->buscarBtn->Size = System::Drawing::Size(98, 23);
			this->buscarBtn->TabIndex = 12;
			this->buscarBtn->Text = L"Buscar";
			this->buscarBtn->UseVisualStyleBackColor = true;
			this->buscarBtn->Click += gcnew System::EventHandler(this, &MyForm1::buscarBtn_Click);
			// 
			// ordenarBtn
			// 
			this->ordenarBtn->Location = System::Drawing::Point(21, 97);
			this->ordenarBtn->Name = L"ordenarBtn";
			this->ordenarBtn->Size = System::Drawing::Size(98, 23);
			this->ordenarBtn->TabIndex = 12;
			this->ordenarBtn->Text = L"Ordenar";
			this->ordenarBtn->UseVisualStyleBackColor = true;
			this->ordenarBtn->Click += gcnew System::EventHandler(this, &MyForm1::ordenarBtn_Click);
			// 
			// prioridadRbtn
			// 
			this->prioridadRbtn->AutoSize = true;
			this->prioridadRbtn->Location = System::Drawing::Point(6, 65);
			this->prioridadRbtn->Name = L"prioridadRbtn";
			this->prioridadRbtn->Size = System::Drawing::Size(66, 17);
			this->prioridadRbtn->TabIndex = 2;
			this->prioridadRbtn->Text = L"Prioridad";
			this->prioridadRbtn->UseVisualStyleBackColor = true;
			// 
			// fechaRbtn
			// 
			this->fechaRbtn->AutoSize = true;
			this->fechaRbtn->Location = System::Drawing::Point(6, 42);
			this->fechaRbtn->Name = L"fechaRbtn";
			this->fechaRbtn->Size = System::Drawing::Size(55, 17);
			this->fechaRbtn->TabIndex = 1;
			this->fechaRbtn->Text = L"Fecha";
			this->fechaRbtn->UseVisualStyleBackColor = true;
			// 
			// idRbtn
			// 
			this->idRbtn->AutoSize = true;
			this->idRbtn->Checked = true;
			this->idRbtn->Location = System::Drawing::Point(6, 19);
			this->idRbtn->Name = L"idRbtn";
			this->idRbtn->Size = System::Drawing::Size(36, 17);
			this->idRbtn->TabIndex = 0;
			this->idRbtn->TabStop = true;
			this->idRbtn->Text = L"ID";
			this->idRbtn->UseVisualStyleBackColor = true;
			// 
			// exportarBtn
			// 
			this->exportarBtn->Location = System::Drawing::Point(553, 274);
			this->exportarBtn->Name = L"exportarBtn";
			this->exportarBtn->Size = System::Drawing::Size(98, 23);
			this->exportarBtn->TabIndex = 12;
			this->exportarBtn->Text = L"Exportar Agenda";
			this->exportarBtn->UseVisualStyleBackColor = true;
			this->exportarBtn->Click += gcnew System::EventHandler(this, &MyForm1::exportarBtn_Click);
			// 
			// abrirCarpeta
			// 
			this->abrirCarpeta->SelectedPath = L"..//";
			// 
			// timer1
			// 
			this->timer1->Interval = 60000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(773, 322);
			this->Controls->Add(this->exportarBtn);
			this->Controls->Add(this->groupBox1);
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
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->EnabledChanged += gcnew System::EventHandler(this, &MyForm1::MyForm1_EnabledChanged);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		MyForm2^ formulario;
		Usuario^ persona;

		//Muestra el formulario de inicio de sesión cuando este se cierra
	private: System::Void OnClosing(System::Object^  sender, FormClosingEventArgs^  e) {
		this->Owner->Show();
	}

			 //Muestra las tareas del usuario en el nuevo día seleccionado
	private: System::Void calendario_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {
		MostrarTareas(calendario->SelectionStart);
	}

			 //Muestra las taareas del día especificado
	private: System::Void MostrarTareas(DateTime^ dia) {
		tareasLbl->Text = "Tareas " + dia->ToString("dd/MM/yyyy") + ":";
		tareasTbx->Text = persona->MostrarTareasDía(dia);
	}

			 //Cambia el mes y el año por los nuevos especificados
	private: System::Void fechaBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			calendario->SelectionStart = Convert::ToDateTime(mesTbx->Text + "/" + añoTbx->Text);
		}
		catch (...) {
			MessageBox::Show("La fecha ingresada no es válida", "Error");
		}
	}

			 //Muestra el formulario para agregar nuevas tareas
	private: System::Void agregarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		formulario = gcnew MyForm2(persona, calendario->SelectionStart);
		formulario->Show(this);
		this->Enabled = false;
	}

			 //Llama a la función para mostrar las tareas
	private: System::Void MyForm1_EnabledChanged(System::Object^  sender, System::EventArgs^  e) {
		MostrarTareas(calendario->SelectionStart);
	}

			 //Ordena los eventos según el parámetro indicado
	private: System::Void ordenarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (idRbtn->Checked) {
			persona->Ordenar(0);
		}
		else if (fechaRbtn->Checked) {
			persona->Ordenar(1);
		}
		else {
			persona->Ordenar(2);
		}
		MostrarTareas(calendario->SelectionStart);
	}

			 //Busca un evento y muestra un mensaje con todos los resultados de la búsqueda
	private: System::Void buscarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			String^ resultado = "";
			if (idRbtn->Checked) {
				resultado = persona->Buscar(0, valorTbx->Text);
			}
			else if (fechaRbtn->Checked) {
				resultado = persona->Buscar(1, valorTbx->Text);
			}
			else {
				resultado = persona->Buscar(2, valorTbx->Text);
			}
			MessageBox::Show(resultado, "Resultado de la búsqueda");
		}
		catch (...) {
			MessageBox::Show("El dato a buscar no es válido", "Error");
		}
	}

			 //Solicita una ubicación y exporta el archivo con la agenda del ususario
	private: System::Void exportarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			abrirCarpeta->SelectedPath = "..//";
			abrirCarpeta->ShowDialog();
			StreamWriter^ escritor = gcnew StreamWriter(abrirCarpeta->SelectedPath + "//" + persona->nombre + ".txt", false);
			escritor->Write(persona->Exportar());
			escritor->Close();
			MessageBox::Show("La agenda se exportó exitosamente", "Exportación finalizada");
		}
		catch (...) {
			MessageBox::Show("Ocurrió un error al exportar", "Error");
		}
	}

			 //Revisa cada minuto si ocurre algún evento
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		DateTime^ hora = gcnew DateTime(2019, 11, 16);
		persona->RevisarEventos(hora->Now);
		MostrarTareas(calendario->SelectionStart);
	}

			 //Inicia el temporizador
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
		timer1->Start();
	}
};
}
