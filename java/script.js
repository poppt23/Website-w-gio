 /* GROUPS FIELDS INTO OBJECTS */
document.addEventListener("DOMContentLoaded", function() {
    fields.firstname = document.getElementById('firsnname');
    fields.lastname = document.getElementById('lastname');
    fields.email = document.getElementById('email');
    fields.country = document.getElementById('country');
    fields.subject = document.getElementById('subject');
   })

   /* CHECKS TO SEE IF USER INPUT A VALUE */
   function isNotEmpty(value) {
    if (value == null || typeof value == 'undefined' ) return false;
    return (value.length > 0);
   }

    /* CHECKS TO SEE EMAIL VALUE IS ACCEPTABLE */
   function isEmail(email) {
       let regex = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-p-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9]{0,61}[a-zA-Z0-9])?)*$/;
       return regex.test(String(email).toLowerCase());
   }

    /* VALIDS FIELD INPUTS */
   function fieldValidation(field, validationFunction) {
    if (field == null) return false;
   
    let isFieldValid = validationFunction(field.value)
    if (!isFieldValid) {
    field.className = 'placeholderRed';
    } else {
    field.className = '';
    }
   
    return isFieldValid;
   }

   /* VALIDS INPUTS */
   function isValid() {
    var valid = true;
    
    valid &= fieldValidation(fields.firstname, isNotEmpty);
    valid &= fieldValidation(fields.lastname, isNotEmpty);
    valid &= fieldValidation(fields.country, isNotEmpty);
    valid &= fieldValidation(fields.email, isEmail);
    valid &= fieldValidation(fields.subject, isNotEmpty);
   
    return valid;
   }

   class User {
    constructor(firstname, lastname, country, email, subject) {
    this.firstName = firstname;
    this.lastName = lastname;
    this.country = country;
    this.email = email;
    this.subject = subject;
    }
   }


   function sendContact(){

    if (isValid()) {
        let usr = new User(firstname.value, lastname.value, country.value, email.value);

        alert(`${esr.firstname} Thank you for your message!`)
    }
    else{
        alert("There was an error")
    }
   }