#pragma once

namespace Final {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form
    {
    public:
        MyForm()
        {
            InitializeComponent();
            AddCurrencies();  // Initialize currencies in ComboBoxes
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ amountTextBox;
    private: System::Windows::Forms::Label^ fromLabel;
    private: System::Windows::Forms::Label^ toLabel;
    private: System::Windows::Forms::ComboBox^ fromComboBox;
    private: System::Windows::Forms::ComboBox^ toComboBox;
    private: System::Windows::Forms::Button^ convertButton;
    private: System::Windows::Forms::Label^ resultLabel;

    private: System::ComponentModel::Container^ components;

    private: array<String^>^ currencies;  // Array to store currency codes

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->amountTextBox = (gcnew System::Windows::Forms::TextBox());
               this->fromLabel = (gcnew System::Windows::Forms::Label());
               this->toLabel = (gcnew System::Windows::Forms::Label());
               this->fromComboBox = (gcnew System::Windows::Forms::ComboBox());
               this->toComboBox = (gcnew System::Windows::Forms::ComboBox());
               this->convertButton = (gcnew System::Windows::Forms::Button());
               this->resultLabel = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // amountTextBox
               // 
               this->amountTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->amountTextBox->Location = System::Drawing::Point(118, 53);
               this->amountTextBox->Name = L"amountTextBox";
               this->amountTextBox->Size = System::Drawing::Size(146, 45);
               this->amountTextBox->TabIndex = 0;
               // 
               // fromLabel
               // 
               this->fromLabel->AutoSize = true;
               this->fromLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->fromLabel->Location = System::Drawing::Point(72, 134);
               this->fromLabel->Name = L"fromLabel";
               this->fromLabel->Size = System::Drawing::Size(105, 39);
               this->fromLabel->TabIndex = 1;
               this->fromLabel->Text = L"From:";
               // 
               // toLabel
               // 
               this->toLabel->AutoSize = true;
               this->toLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->toLabel->Location = System::Drawing::Point(72, 211);
               this->toLabel->Name = L"toLabel";
               this->toLabel->Size = System::Drawing::Size(66, 39);
               this->toLabel->TabIndex = 2;
               this->toLabel->Text = L"To:";
               // 
               // fromComboBox
               // 
               this->fromComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->fromComboBox->FormattingEnabled = true;
               this->fromComboBox->Location = System::Drawing::Point(205, 127);
               this->fromComboBox->Name = L"fromComboBox";
               this->fromComboBox->Size = System::Drawing::Size(104, 46);
               this->fromComboBox->TabIndex = 3;
               // 
               // toComboBox
               // 
               this->toComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->toComboBox->FormattingEnabled = true;
               this->toComboBox->Location = System::Drawing::Point(199, 218);
               this->toComboBox->Name = L"toComboBox";
               this->toComboBox->Size = System::Drawing::Size(110, 46);
               this->toComboBox->TabIndex = 4;
               // 
               // convertButton
               // 
               this->convertButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->convertButton->Location = System::Drawing::Point(332, 197);
               this->convertButton->Name = L"convertButton";
               this->convertButton->Size = System::Drawing::Size(214, 67);
               this->convertButton->TabIndex = 5;
               this->convertButton->Text = L"Convert";
               this->convertButton->UseVisualStyleBackColor = true;
               this->convertButton->Click += gcnew System::EventHandler(this, &MyForm::convertButton_Click);
               // 
               // resultLabel
               // 
               this->resultLabel->AutoSize = true;
               this->resultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->resultLabel->Location = System::Drawing::Point(127, 321);
               this->resultLabel->Name = L"resultLabel";
               this->resultLabel->Size = System::Drawing::Size(123, 39);
               this->resultLabel->TabIndex = 6;
               this->resultLabel->Text = L"Result:";
               // 
               // MyForm
               // 
               this->ClientSize = System::Drawing::Size(590, 493);
               this->Controls->Add(this->amountTextBox);
               this->Controls->Add(this->fromLabel);
               this->Controls->Add(this->toLabel);
               this->Controls->Add(this->fromComboBox);
               this->Controls->Add(this->toComboBox);
               this->Controls->Add(this->convertButton);
               this->Controls->Add(this->resultLabel);
               this->Name = L"MyForm";
               this->Text = L"Currency Converter";
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

           // Event handler for the convert button click
           System::Void convertButton_Click(System::Object^ sender, System::EventArgs^ e)
           {
               // Convert the amount to double
               double amount;
               if (!Double::TryParse(amountTextBox->Text, amount))
               {
                   MessageBox::Show("Invalid amount. Please enter a valid number.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   return;
               }

               // Get the selected currencies
               String^ fromCurrency = fromComboBox->Text;
               String^ toCurrency = toComboBox->Text;

               // Perform the conversion (using fixed exchange rates for simplicity)
               double exchangeRate = GetExchangeRate(fromCurrency, toCurrency);
               double result = amount * exchangeRate;

               // Display the result
               resultLabel->Text = "Result: " + result.ToString("F2") + " " + toCurrency;
           }

           // Get the exchange rate (replace with actual API call in a real-world scenario)
           double GetExchangeRate(String^ fromCurrency, String^ toCurrency)
           {
               // For simplicity, using fixed exchange rates (replace with actual rates)
               if (fromCurrency == "USD" && toCurrency == "EUR")
                   return 0.85;  // 1 USD = 0.85 EUR
               else if (fromCurrency == "USD" && toCurrency == "GBP")
                   return 0.75;  // 1 USD = 0.75 GBP
               else if (fromCurrency == "EUR" && toCurrency == "USD")
                   return 1.18;  // 1 EUR = 1.18 USD
               else if (fromCurrency == "EUR" && toCurrency == "GBP")
                   return 0.88;  // 1 EUR = 0.88 GBP
               else if (fromCurrency == "GBP" && toCurrency == "USD")
                   return 1.33;  // 1 GBP = 1.33 USD
               else if (fromCurrency == "GBP" && toCurrency == "EUR")
                   return 1.14;  // 1 GBP = 1.14 EUR
               else
                   return 1.0;   // Same currency, 1:1 exchange rate
           }

           // Add supported currencies to ComboBoxes
           void AddCurrencies()
           {
               currencies = gcnew array<String^> { "USD", "EUR", "GBP", "JPY", "AUD", "CAD", "CNY", "INR", "BRL", "RUB", "MXN", "KRW", "TRY", "ZAR", "IDR", "SEK", "CHF", "NOK", "NZD", "SGD" };

               fromComboBox->Items->AddRange(currencies);
               toComboBox->Items->AddRange(currencies);

               // Set default currencies
               fromComboBox->SelectedIndex = 0;
               toComboBox->SelectedIndex = 1;
           }
    };
}