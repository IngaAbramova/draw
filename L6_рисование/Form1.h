#pragma once
namespace L6_��������� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
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
			this->button1->Text = L"��������";
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
			//BackgroundImage-���������� ��� ������ ������� �����������, ������������ �� �������� ����������.
	        if(pictureBox1->BackgroundImage == nullptr)
			pictureBox1->BackgroundImage = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			//Graphics ����� ������������� ������ ��� ��������� �������� �� ���������� �����������. 
			//������� ����� ������ Graphics �� ���������� ������� Image.
			//Graphics.FromImage(Image) Method
			Graphics^ Graph = Graphics::FromImage(pictureBox1->BackgroundImage);			
            //������� ��� ����������� ��������� � ��������� ������� ����������� ��������� ������ ����.
			Graph->Clear(System::Drawing::Color::White);
            //����� ��� ���������� ������ - ��������
			Point point1 = Point(180, 152);
			Point point2 = Point(230, 230);
			Point point3 = Point(430, 230);
			Point point4 = Point(480, 152);
			//����� ��� ���������� ������ - �����������
			Point point5 = Point(330, 10);
			Point point6 = Point(300, 15);
			Point point7 = Point(330, 20);
			//������� ������� ����� ��� ���������� �����
			array<Point>^ curvePoints = { point1, point2, point3, point4 };
			array<Point>^ curvePoints2 = { point5, point6, point7};
			//������ �������� � ����������� �� ������� ������
			Graph->FillPolygon(Brushes::Pink, curvePoints);
			Graph->FillPolygon(Brushes::Red, curvePoints2);
			//�������� ������������ ����� �������� �����
			//DrawLine - �������� �����, ����������� ��� �����, ���������� ������ ���������
			//��������� Pen ���������� ����, ������ � ����� �����.
			Graph->DrawLine(Pens::Red, 330, 150, 330,10 );
			//�������� ��������� ����� - ������ ��������
			float x=0;
			for(float x=0; x<700; x+=1)
			{
			//DrawLine - �������� �����, ����������� ��� �����, ���������� ������ ���������
			Graph->DrawLine(Pens::Blue, x, (5*Math::Cos(0.1*x)+195), x+1, (5*Math::Cos(0.1*(x+1))+195));
			}
			//�������� ����
			//FillEllipse - ��������� ���������� ����� �������, ������������� �������������� ���������������, �������� � ������� ���� ���������, ������ � ������.
            //FillEllipse (System.Drawing.Brush brush, int x, int y, int width, int height);
			Graph->FillEllipse(Brushes::Yellow, 520, 40, 70, 70);
			//������ ����
			//DrawArc - ������ ����, ������� �������� ������ �������, ��������� ����� ���������, ������� � �������
			Graph->DrawArc(Pens::Red, 280, 30, 120, 120, 260, 200);
			//�������� ����� ����
			//FillPie - ��������� ���������� ����� �������, ������������� ��������, ������� ����� ����� ���������, �������, ������� � ����� ����������� �������.
			Graph->FillPie(Brushes::Red, 280, 30, 120, 120, 270, 180);
			//������� �����������
		    pictureBox1->Invalidate();
			 }

	
};
}

