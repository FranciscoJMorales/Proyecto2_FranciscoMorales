#include "Actividad.h"


//Constructor utilizado cuando la información proviene del archivo .txt
Actividad::Actividad(System::String^ info)
{
	sig = nullptr;
	ant = nullptr;
	id = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	descripción = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	día = System::Convert::ToInt32(info->Substring(0, info->IndexOf("/")));
	info = info->Remove(0, info->IndexOf("/") + 1);
	mes = System::Convert::ToInt32(info->Substring(0, info->IndexOf("/")));
	info = info->Remove(0, info->IndexOf("/") + 1);
	año = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	horaInicio = System::Convert::ToInt32(info->Substring(0, info->IndexOf(":")));
	info = info->Remove(0, info->IndexOf(":") + 1);
	minutosInicio = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	horaFin = System::Convert::ToInt32(info->Substring(0, info->IndexOf(":")));
	info = info->Remove(0, info->IndexOf(":") + 1);
	minutosFin = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	prioridad = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	personas = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	lugar = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	materiales = msclr::interop::marshal_as<std::string>(info);
}

//Constructor utilizado en la creación de nuevas actividades
Actividad::Actividad(int ID, System::String^ info, System::DateTime^ fecha, int hF, int minF, int P, System::String^ people, System::String^ place, System::String^ material)
{
	sig = nullptr;
	ant = nullptr;
	id = ID;
	descripción = msclr::interop::marshal_as<std::string>(info);
	año = fecha->Year;
	mes = fecha->Month;
	día = fecha->Day;
	horaInicio = fecha->Hour;
	minutosInicio = fecha->Minute;
	horaFin = hF;
	minutosFin = minF;
	prioridad = P;
	personas = msclr::interop::marshal_as<std::string>(people);
	lugar = msclr::interop::marshal_as<std::string>(place);
	materiales = msclr::interop::marshal_as<std::string>(material);
}


Actividad::~Actividad()
{
}

//Redefinición de la función virtual para mostrar el estado de la actividad
System::String^ Actividad::ToString() const {
	System::String^ texto = "Actividad," + System::Convert::ToString(id) + "," + gcnew System::String(descripción.c_str()) + ",";
	System::DateTime^ fechaIn = gcnew System::DateTime(año, mes, día);
	texto += fechaIn->ToString("dd/MM/yyyy") + "," + System::Convert::ToString(horaInicio) + ":" + System::Convert::ToString(minutosInicio) + ",";
	texto += System::Convert::ToString(horaFin) + ":" + System::Convert::ToString(minutosFin) + "," + System::Convert::ToString(prioridad) + ",";
	texto += gcnew System::String(personas.c_str()) + "," + gcnew System::String(lugar.c_str()) + "," + gcnew System::String(materiales.c_str()) + "\r\n";
	return texto;
}

//Redefinición de la función virtual para cuando ocurre el evento
bool Actividad::Mostrar() const {
	System::Windows::Forms::MessageBox::Show(ToString(), "Actividad");
	return false;
}