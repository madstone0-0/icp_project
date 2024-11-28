#include "StudentSignUpForm.h"
#include "../services/UserService.h" // Assuming you have a service for registration

namespace icpproject {

    // Constructor for the form
    StudentSignUpForm::StudentSignUpForm(void)
    {
        InitializeComponent();
    }

    StudentSignUpForm::StudentSignUpForm(IChildHost^ parent)
    {
        this->parent = parent;
        InitializeComponent();
    }

    // Destructor to clean up resources
    StudentSignUpForm::~StudentSignUpForm()
    {
        if (components)
        {
            delete components;
        }
    }

    // Event handler for the Sign Up button click
    void StudentSignUpForm::signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ firstName = firstNameTB->Text;
        String^ lastName = lastNameTB->Text;
        String^ email = emailTB->Text;
        String^ password = passwordTB->Text;
        String^ confirmPassword = confirmPasswordTB->Text;

        // Validate inputs
        if (firstName->Length == 0 || lastName->Length == 0 || email->Length == 0 || password->Length == 0)
        {
            MessageBox::Show("Please fill in all the fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Confirm password matches
        if (password != confirmPassword)
        {
            MessageBox::Show("Passwords do not match.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Call the registration service to register the student
        try
        {
            RegistrationService^ registrationService = gcnew RegistrationService();
            bool success = registrationService->RegisterStudent(firstName, lastName, email, password);

            if (success)
            {
                MessageBox::Show("Registration successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                // Optionally, you can redirect the user to the login form after successful registration
                this->Close();
            }
            else
            {
                MessageBox::Show("Registration failed. Please try again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    // Event handler for the Cancel button click
    void StudentSignUpForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close(); // Close the sign-up form
    }
}
