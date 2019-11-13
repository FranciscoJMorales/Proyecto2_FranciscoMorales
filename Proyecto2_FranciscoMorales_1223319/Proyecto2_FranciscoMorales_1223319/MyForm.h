#pragma once
#include "Evento.h"
#include "Lista.h"
#include "Actividad.h"
#include "Recordatorio.h"
#include "Alarma.h"
#include "Usuario.h"
#include "MyForm1.h"

namespace Proyecto2_FranciscoMorales_1223319 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  usuarioTbx;
	private: System::Windows::Forms::Button^  iniciarBtn;
	private: System::Windows::Forms::Button^  registrarBtn;



	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  contraseñaTbx;
	private: System::Windows::Forms::Button^  importarBtn;
	private: System::Windows::Forms::OpenFileDialog^  abrirArchivo;




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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->usuarioTbx = (gcnew System::Windows::Forms::TextBox());
			this->iniciarBtn = (gcnew System::Windows::Forms::Button());
			this->registrarBtn = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->contraseñaTbx = (gcnew System::Windows::Forms::TextBox());
			this->importarBtn = (gcnew System::Windows::Forms::Button());
			this->abrirArchivo = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(61, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Agenda";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Usuario:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Contraseña:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(102, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"o";
			// 
			// usuarioTbx
			// 
			this->usuarioTbx->Location = System::Drawing::Point(82, 94);
			this->usuarioTbx->Name = L"usuarioTbx";
			this->usuarioTbx->Size = System::Drawing::Size(100, 20);
			this->usuarioTbx->TabIndex = 4;
			// 
			// iniciarBtn
			// 
			this->iniciarBtn->Location = System::Drawing::Point(65, 175);
			this->iniciarBtn->Name = L"iniciarBtn";
			this->iniciarBtn->Size = System::Drawing::Size(92, 23);
			this->iniciarBtn->TabIndex = 7;
			this->iniciarBtn->Text = L"Inicia Sesión";
			this->iniciarBtn->UseVisualStyleBackColor = true;
			this->iniciarBtn->Click += gcnew System::EventHandler(this, &MyForm::iniciarBtn_Click);
			// 
			// registrarBtn
			// 
			this->registrarBtn->Location = System::Drawing::Point(65, 217);
			this->registrarBtn->Name = L"registrarBtn";
			this->registrarBtn->Size = System::Drawing::Size(92, 23);
			this->registrarBtn->TabIndex = 9;
			this->registrarBtn->Text = L"Regístrate";
			this->registrarBtn->UseVisualStyleBackColor = true;
			this->registrarBtn->Click += gcnew System::EventHandler(this, &MyForm::registrarBtn_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 302);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(105, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"© Skynet S.A., 2019";
			// 
			// contraseñaTbx
			// 
			this->contraseñaTbx->Location = System::Drawing::Point(82, 136);
			this->contraseñaTbx->Name = L"contraseñaTbx";
			this->contraseñaTbx->PasswordChar = '*';
			this->contraseñaTbx->Size = System::Drawing::Size(100, 20);
			this->contraseñaTbx->TabIndex = 6;
			// 
			// importarBtn
			// 
			this->importarBtn->Location = System::Drawing::Point(60, 270);
			this->importarBtn->Name = L"importarBtn";
			this->importarBtn->Size = System::Drawing::Size(103, 23);
			this->importarBtn->TabIndex = 10;
			this->importarBtn->Text = L"Importar Agenda";
			this->importarBtn->UseVisualStyleBackColor = true;
			this->importarBtn->Click += gcnew System::EventHandler(this, &MyForm::importarBtn_Click);
			// 
			// abrirArchivo
			// 
			this->abrirArchivo->InitialDirectory = L"..//";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(221, 324);
			this->Controls->Add(this->importarBtn);
			this->Controls->Add(this->contraseñaTbx);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->registrarBtn);
			this->Controls->Add(this->iniciarBtn);
			this->Controls->Add(this->usuarioTbx);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Agenda";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		MyForm1^ agenda;

	private: System::Void iniciarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (usuarioTbx->Text != "" && contraseñaTbx->Text != "") {
			StreamReader^ lector = gcnew StreamReader("..//Users.txt");
			String^ valor = usuarioTbx->Text + "," + contraseñaTbx->Text;
			String^ usuarios = lector->ReadToEnd();
			lector->Close();
			while (usuarios->IndexOf("\r\n") != -1) {
				String^ usuarioA = usuarios->Substring(0, usuarios->IndexOf("\r\n"));
				usuarios = usuarios->Remove(0, usuarios->IndexOf("\r\n") + 2);
				if (usuarioA == valor) {
					usuarios = "A";
					lector = gcnew StreamReader("..//" + usuarioTbx->Text + ".txt");
					agenda = gcnew MyForm1(lector->ReadToEnd());
					lector->Close();
					agenda->Show(this);
					usuarioTbx->Clear();
					contraseñaTbx->Clear();
					this->Hide();
				}
			}
			if (usuarios != "A") {
				MessageBox::Show("El usuario o la contraseña no son válidos.", "Error al iniciar sesión");
			}
		}
		else {
			MessageBox::Show("Debe ingresar un usuario y una contraseña.", "Error al iniciar sesión");
		}
	}

	private: System::Void registrarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (usuarioTbx->Text != "" && contraseñaTbx->Text != "") {
			StreamReader^ lector = gcnew StreamReader("..//Users.txt", true);
			String^ usuarios = lector->ReadToEnd();
			lector->Close();
			while (usuarios->IndexOf("\r\n") != -1) {
				String^ usuarioA = usuarios->Substring(0, usuarios->IndexOf(","));
				usuarios = usuarios->Remove(0, usuarios->IndexOf("\r\n") + 2);
				if (usuarioA == usuarioTbx->Text) {
					usuarios = "A";
					MessageBox::Show("El usuario ya existe.", "Error al registrarse");
				}
			}
			if (usuarios != "A") {
				StreamWriter^ escritor = gcnew StreamWriter("..//Users.txt", true);
				escritor->Write(usuarioTbx->Text + "," + contraseñaTbx->Text + "\r\n");
				escritor->Close();
				escritor = gcnew StreamWriter("..//" + usuarioTbx->Text + ".txt");
				escritor->Write(usuarioTbx->Text + "," + contraseñaTbx->Text + "\r\n");
				escritor->Close();
				lector = gcnew StreamReader("..//" + usuarioTbx->Text + ".txt");
				agenda = gcnew MyForm1(lector->ReadToEnd()); 
				lector->Close();
				agenda->Show(this);
				usuarioTbx->Clear();
				contraseñaTbx->Clear();
				this->Hide();
			}
		}
		else {
			MessageBox::Show("Debe ingresar un usuario y una contraseña.", "Error al registrarse");
		}
	}

	private: System::Void importarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			abrirArchivo->FileName = "";
			abrirArchivo->ShowDialog();
			String^ direccion = abrirArchivo->FileName;
			StreamReader^ lector = gcnew StreamReader(direccion);
			String^ user = lector->ReadToEnd();
			lector->Close();
			String^ nombre = user->Substring(0, user->IndexOf(","));
			lector = gcnew StreamReader("..//Users.txt", true);
			String^ usuarios = lector->ReadToEnd();
			lector->Close();
			while (usuarios->IndexOf("\r\n") != -1) {
				String^ usuarioA = usuarios->Substring(0, usuarios->IndexOf(","));
				usuarios = usuarios->Remove(0, usuarios->IndexOf("\r\n") + 2);
				if (usuarioA == nombre) {
					usuarios = "A";
					MessageBox::Show("El usuario ya existe.", "Error al importar");
				}
			}
			if (usuarios != "A") {
				agenda = gcnew MyForm1(user);
				user = user->Substring(0, user->IndexOf("\r\n") + 2);
				StreamWriter^ escritor = gcnew StreamWriter("..//Users.txt", true);
				escritor->Write(user);
				escritor->Close();
				escritor = gcnew StreamWriter("..//" + nombre + ".txt");
				escritor->Write(user);
				escritor->Close();
				MessageBox::Show("La agenda se importó exitosamente", "Carga finalizada");
				agenda->Show(this);
				usuarioTbx->Clear();
				contraseñaTbx->Clear();
				this->Hide();
			}
		}
		catch (...) {
			MessageBox::Show("El formato de entrada o el archivo no es válido.", "Error");
		}
	}
};
}