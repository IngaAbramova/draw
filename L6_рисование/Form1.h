#pragma once
namespace L6_рисование {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;



	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(-3, -3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(852, 343);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(880, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(193, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Рисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1097, 340);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			//BackgroundImage-Возвращает или задает фоновое изображение, отображаемое на элементе управления.
	        if(pictureBox1->BackgroundImage == nullptr)
			pictureBox1->BackgroundImage = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			//Graphics Класс предоставляет методы для рисования объектов на устройстве отображения. 
			//Создает новый объект Graphics из указанного рисунка Image.
			//Graphics.FromImage(Image) Method
			Graphics^ Graph = Graphics::FromImage(pictureBox1->BackgroundImage);			
            //Очищает всю поверхность рисования и выполняет заливку поверхности указанным цветом фона.
			Graph->Clear(System::Drawing::Color::White);
            //Точки для построения фигуры - трапеция
			Point point1 = Point(180, 152);
			Point point2 = Point(230, 230);
			Point point3 = Point(430, 230);
			Point point4 = Point(480, 152);
			//Точки для построения фигуры - треугольник
			Point point5 = Point(330, 10);
			Point point6 = Point(300, 15);
			Point point7 = Point(330, 20);
			//Создаем массивы точек для построения фигур
			array<Point>^ curvePoints = { point1, point2, point3, point4 };
			array<Point>^ curvePoints2 = { point5, point6, point7};
			//Рисуем трапецию и закрашиваем ее розовым цветом
			Graph->FillPolygon(Brushes::Pink, curvePoints);
			Graph->FillPolygon(Brushes::Red, curvePoints2);
			//Нарисуем вертикальную линию красного цвета
			//DrawLine - Проводит линию, соединяющую две точки, задаваемые парами координат
			//Структура Pen определяет цвет, ширину и стиль линии.
			Graph->DrawLine(Pens::Red, 330, 150, 330,10 );
			//Нарисуем волнистую линию - график косинуса
			float x=0;
			for(float x=0; x<700; x+=1)
			{
			//DrawLine - Проводит линию, соединяющую две точки, задаваемые парами координат
			Graph->DrawLine(Pens::Blue, x, (5*Math::Cos(0.1*x)+195), x+1, (5*Math::Cos(0.1*(x+1))+195));
			}
			//Нарисуем круг
			//FillEllipse - Заполняет внутреннюю часть эллипса, определяемого ограничивающим прямоугольником, заданным с помощью пары координат, ширины и высоты.
            //FillEllipse (System.Drawing.Brush brush, int x, int y, int width, int height);
			Graph->FillEllipse(Brushes::Yellow, 520, 40, 70, 70);
			//Рисуем дугу
			//DrawArc - Рисует дугу, которая является частью эллипса, заданного парой координат, шириной и высотой
			Graph->DrawArc(Pens::Red, 280, 30, 120, 120, 260, 200);
			//Закрасим часть дуги
			//FillPie - Заполняет внутреннюю часть сектора, определяемого эллипсом, который задан парой координат, шириной, высотой и двумя радиальными линиями.
			Graph->FillPie(Brushes::Red, 280, 30, 120, 120, 270, 180);
			//Обновим изображение
		    pictureBox1->Invalidate();
			 }

	
};
}

