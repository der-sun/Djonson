//Реализация Алгоритма Джонсона с помощью взвешанного
//ориентированного графа.
//
//Программа осуществляет поиск кратчайших путей между всеми парами вершин
//взвешанного ориентированного графа, ввод осуществляется с помощью матрицы.
//В программе предусмотрена визуализация, а также описание алгоритма.
//
//Версия: 0.9.0.1
//Разработчик: Виноградов А.А.

#pragma once
#include <climits>
#include <vector>

namespace Djonson {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->helpToolStripMenuItem,
					this->aboutToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1151, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(64, 24);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(47, 24);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeight = 29;
			this->dataGridView1->Location = System::Drawing::Point(26, 47);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(384, 345);
			this->dataGridView1->TabIndex = 1;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 21);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(35, 20);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"2";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(47, 21);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(35, 20);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"3";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(88, 21);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(35, 20);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"4";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(129, 21);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(35, 20);
			this->radioButton4->TabIndex = 5;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"5";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(170, 21);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(35, 20);
			this->radioButton5->TabIndex = 6;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"6";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 473);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 30);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Выбрать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Location = System::Drawing::Point(48, 409);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(213, 58);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Количество вершин";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(430, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(700, 500);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(174, 473);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 30);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Построить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(410, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1151, 581);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Johnson Algorithm Visualization";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	array<array<int>^>^ FindShortestPaths(DataGridView^ dataGridView) {
		int INF = Int32::MaxValue / 2; // Используем половину от Int32::MaxValue для предотвращения переполнения
		int size = dataGridView->RowCount;
		array<array<int>^>^ adjMatrix = GetAdjacencyMatrix(dataGridView);

		array<array<int>^>^ dist = gcnew array<array<int>^>(size); // Массив для хранения кратчайших расстояний
		for (int i = 0; i < size; ++i) {
			dist[i] = gcnew array<int>(size);
			for (int j = 0; j < size; ++j) {
				dist[i][j] = adjMatrix[i][j];
			}
		}

		// Алгоритм Джонсона
		array<int>^ h = gcnew array<int>(size);
		for (int i = 0; i < size; ++i) {
			h[i] = 0; // Устанавливаем начальные значения равными нулю
		}

		array<array<int>^>^ newGraph = gcnew array<array<int>^>(size + 1); // Получаем новый граф через добавления фиктивной вершины
		for (int i = 0; i < size + 1; ++i) {
			newGraph[i] = gcnew array<int>(size + 1);
			for (int j = 0; j < size + 1; ++j) {
				newGraph[i][j] = (i == size || j == size) ? 0 : adjMatrix[i][j];
			}
		}

		// используем алгоритм Беллмана-Форда для получения потенциалов
		array<int>^ potentials = BellmanFord(newGraph, size + 1, size);
		for (int i = 0; i < size; ++i) {
			h[i] = potentials[i];
		}

		// Применяем потенциалы к исходному графу
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (adjMatrix[i][j] != 0) {
					adjMatrix[i][j] += h[i] - h[j];
				}
			}
		}

		// Используем алгоритм Дейкстры для поиска кратчайших путей
		for (int u = 0; u < size; ++u) {
			array<int>^ d = Dijkstra(adjMatrix, size, u);
			for (int v = 0; v < size; ++v) {
				dist[u][v] = (d[v] == INF) ? INF : d[v] + h[v] - h[u];
			}
		}

		return dist;
	}

// Алгоритм Беллмана-Форда для нахождения потенциалов
	array<int>^ BellmanFord(array<array<int>^>^ graph, int size, int source) {
		array<int>^ dist = gcnew array<int>(size);
		for (int i = 0; i < size; ++i) {
			dist[i] = Int32::MaxValue / 2;
		}
		dist[source] = 0;

		for (int i = 0; i < size - 1; ++i) {
			for (int u = 0; u < size; ++u) {
				for (int v = 0; v < size; ++v) {
					if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
						dist[v] = dist[u] + graph[u][v];
					}
				}
			}
		}

		return dist;
	}

// Алгоритм Дейкстры для поиска кратчайших путей
	array<int>^ Dijkstra(array<array<int>^>^ graph, int size, int source) {
		array<int>^ dist = gcnew array<int>(size);
		array<bool>^ visited = gcnew array<bool>(size);
		for (int i = 0; i < size; ++i) {
			dist[i] = Int32::MaxValue / 2;
			visited[i] = false;
		}
		dist[source] = 0;

		for (int count = 0; count < size - 1; ++count) {
			int u = -1;
			for (int v = 0; v < size; ++v) {
				if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
					u = v;
				}
			}

			if (dist[u] == Int32::MaxValue / 2) {
				break;
			}

			visited[u] = true;

			for (int v = 0; v < size; ++v) {
				if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
					dist[v] = dist[u] + graph[u][v];
				}
			}
		}

		return dist;
	}

// Функция для обновления текста в label1 после нахождения минимальных расстояний
	void UpdateLabelWithShortestPaths(DataGridView^ dataGridView, Label^ label) {
		array<array<int>^>^ shortestPaths = FindShortestPaths(dataGridView);

		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		int size = shortestPaths->Length;

		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (i != j && shortestPaths[i][j] != Int32::MaxValue / 2) { // Исключаем пути от вершины к самой себе и пути с INF
					sb->AppendFormat("{0} -> {1}: {2}", i + 1, j + 1, shortestPaths[i][j]);
					sb->AppendLine();
				}
			}
		}

		label->Text = sb->ToString();
	}

// Метод для извлечения матрицы смежности из DataGridView
	array<array<int>^>^ GetAdjacencyMatrix(DataGridView^ dataGridView) {
		int size = dataGridView->RowCount;
		array<array<int>^>^ matrix = gcnew array<array<int>^>(size);

		for (int i = 0; i < size; ++i) {
			matrix[i] = gcnew array<int>(size);
			for (int j = 0; j < size; ++j) {
				if (dataGridView->Rows[i]->Cells[j]->Value != nullptr) {
					String^ valueStr = dataGridView->Rows[i]->Cells[j]->Value->ToString();
					matrix[i][j] = (valueStr != "") ? Convert::ToInt32(valueStr) : Int32::MaxValue / 2;
				}
				else {
					matrix[i][j] = Int32::MaxValue / 2; // Устанавливаем вес ребра на бесконечность для пустой ячейки
				}
			}
		}

		return matrix;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		Graphics^ g = Graphics::FromImage(bitmap);
		g->Clear(Color::Transparent);

		int n;
		if (radioButton1->Checked) n = 2;
		else if (radioButton2->Checked) n = 3;
		else if (radioButton3->Checked) n = 4;
		else if (radioButton4->Checked) n = 5;
		else if (radioButton5->Checked) n = 6;
		else n = 0;

		dataGridView1->ColumnCount = n;
		dataGridView1->RowCount = n;


		for (int i = 0; i < n; i++) {
			dataGridView1->Columns[i]->Name = (i + 1).ToString();
			dataGridView1->Rows[i]->Height = dataGridView1->Height / (n + 1);
			dataGridView1->Rows[i]->HeaderCell->Value = (i + 1).ToString();
		}
		
		button2->Enabled = true;
		button1->Enabled = false;
		radioButton1->Enabled = false;
		radioButton2->Enabled = false;
		radioButton3->Enabled = false;
		radioButton4->Enabled = false;
		radioButton5->Enabled = false;
	}

	private: System::Void DrawGraph(int verticesCount, array<array<int>^>^ adjMatrix) {
		// Вычисление координат для эллипсов
		float centerX = pictureBox1->Width / 2.0f;
		float centerY = pictureBox1->Height / 2.0f;
		float radius = Math::Min(pictureBox1->Width, pictureBox1->Height) / 2.5f;
		float vertexRadius = 10.0f; // Радиус эллипсов

		array<PointF>^ points = gcnew array<PointF>(verticesCount);
		for (int i = 0; i < verticesCount; i++) {
			float angle = 2 * Math::PI * i / verticesCount;
			points[i] = PointF(centerX + radius * Math::Cos(angle), centerY + radius * Math::Sin(angle));
		}

		// Создание и отрисовка графа на поле
		Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		Graphics^ g = Graphics::FromImage(bitmap);
		g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
		g->Clear(Color::Transparent);

		// Добавление стрелок и весов
		for (int i = 0; i < verticesCount; i++) {
			for (int j = 0; j < verticesCount; j++) {
				if (adjMatrix[i][j] != 0) {
					// Посчёт длины и позиции стрелок
					float dx = points[j].X - points[i].X;
					float dy = points[j].Y - points[i].Y;
					float length = Math::Sqrt(dx * dx + dy * dy);

					// Подсчёт начала и конца линии
					PointF start = PointF(
						points[i].X + vertexRadius * dx / length,
						points[i].Y + vertexRadius * dy / length
					);
					PointF end = PointF(
						points[j].X - vertexRadius * dx / length,
						points[j].Y - vertexRadius * dy / length
					);

					// Отрисовка стрелочки
					DrawArrow(g, Pens::Black, start, end);

					// Расчёт позиции для label
					float midX = (start.X + end.X) / 2;
					float midY = (start.Y + end.Y) / 2;

					// Высчитываем перпендикуляр от линии между эллипсами
					float offset = 15; // Отступ от линии
					float offsetX = -dy / length * offset;
					float offsetY = dx / length * offset;

					// Отрисовка веса
					g->DrawString(adjMatrix[i][j].ToString(), gcnew System::Drawing::Font("Arial", 12), Brushes::Black, midX + offsetX, midY + offsetY);
				}
			}
		}

		// Отрисовка эллипсов
		for (int i = 0; i < verticesCount; i++) {
			g->FillEllipse(Brushes::Red, points[i].X - vertexRadius, points[i].Y - vertexRadius, 2 * vertexRadius, 2 * vertexRadius);
			g->DrawString((i + 1).ToString(), gcnew System::Drawing::Font("Arial", 12), Brushes::Black, points[i].X - 6, points[i].Y - 8);
		}

		// Ставим граф на пикчербокс
		pictureBox1->Image = bitmap;
	}

	private: System::Void DrawArrow(Graphics^ g, Pen^ pen, PointF start, PointF end) {
	float arrowSize = 10.0f; // Size of the arrowhead
	float angle = Math::Atan2(end.Y - start.Y, end.X - start.X);

	// Отрисовка линии
	g->DrawLine(pen, start, end);

	// Высчитываем позиции для стрелочки на конце линии
	PointF arrowPoint1 = PointF(
		end.X - arrowSize * Math::Cos(angle + Math::PI / 6),
		end.Y - arrowSize * Math::Sin(angle + Math::PI / 6)
	);
	PointF arrowPoint2 = PointF(
		end.X - arrowSize * Math::Cos(angle - Math::PI / 6),
		end.Y - arrowSize * Math::Sin(angle - Math::PI / 6)
	);

	// Отрисовка стрелочки
	array<PointF>^ arrowHead = gcnew array<PointF>(3) { end, arrowPoint1, arrowPoint2 };
	g->FillPolygon(Brushes::Black, arrowHead);
}

	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Something about", "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Some help", "Help", MessageBoxButtons::OK, MessageBoxIcon::Question);
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		int verticesCount = 2;
		if (radioButton1->Checked) verticesCount = 2;
		else if (radioButton2->Checked) verticesCount = 3;
		else if (radioButton3->Checked) verticesCount = 4;
		else if (radioButton4->Checked) verticesCount = 5;
		else if (radioButton5->Checked) verticesCount = 6;

		// скраппим матрицу из datagridview
		array<array<int>^>^ adjMatrix = gcnew array<array<int>^>(verticesCount);
		for (int i = 0; i < verticesCount; i++) {
			adjMatrix[i] = gcnew array<int>(verticesCount);
			for (int j = 0; j < verticesCount; j++) {
				int value;
				if (Int32::TryParse(dataGridView1[j, i]->Value != nullptr ? dataGridView1[j, i]->Value->ToString() : "0", value)) {
					adjMatrix[i][j] = value;
				}
				else {
					adjMatrix[i][j] = 0;
				}
			}
		}

		// Отрисовка графа
		DrawGraph(verticesCount, adjMatrix);

		UpdateLabelWithShortestPaths(dataGridView1, label1);

		button1->Enabled = true;
		button2->Enabled = false;
		radioButton1->Enabled = true;
		radioButton2->Enabled = true;
		radioButton3->Enabled = true;
		radioButton4->Enabled = true;
		radioButton5->Enabled = true;
	}
};
}
