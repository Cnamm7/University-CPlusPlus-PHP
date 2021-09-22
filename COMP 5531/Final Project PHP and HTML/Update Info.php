<?php
// Initialize the session
session_start();
 
// Check if the user is logged in, if not then redirect him to login page
if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
    header("location: Login.php");
    exit;
}

require_once "Config.php";

// Define variables and initialize with empty values
$companyName = $firstName = $lastName = $profession = $gender = $phoneNumber = "";
$address = $city = $postalCode = $province = "";

$companyName_err = $firstName_err = $lastName_err = $profession_err = $gender_err = $phoneNumber_err = "";
$address_err = $city_err = $postalCode_err = $province_err = "";

$id = $_SESSION["username"];
 
// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){
         
    if(empty(trim($_POST["firstName"]))){
        $firstName_err = "Please enter your firstname.";
    } else{ $firstName = trim($_POST["firstName"]);}
    
    if(empty(trim($_POST["lastName"]))){
        $lastName_err = "Please enter your lastname.";
    } else{ $lastName = trim($_POST["lastName"]);}
    
    if(empty(trim($_POST["companyName"]))){
        $companyName_err = "Please enter your current company name.";
    } else{ $companyName = trim($_POST["companyName"]);}
    
    if(empty(trim($_POST["profession"]))){
        $profession_err = "Please enter your profession.";
    } else{ $profession = trim($_POST["profession"]);}
    
    if(empty(trim($_POST["gender"]))){
        $gender_err = "Please enter your gender.";
    } else{ $gender = trim($_POST["gender"]);}
    
    if(empty(trim($_POST["phoneNumber"]))){
        $phoneNumber_err = "Please enter your phoneNumber.";
    } else{ $phoneNumber = trim($_POST["phoneNumber"]);}
    
    if(empty(trim($_POST["address"]))){
        $address_err = "Please enter your address.";
    } else{ $address = trim($_POST["address"]);}
    
    if(empty(trim($_POST["city"]))){
        $city_err = "Please enter your city.";
    } else{ $city = trim($_POST["city"]);}
    
    if(empty(trim($_POST["postalCode"]))){
        $postalCode_err = "Please enter your postalCode.";
    } else{ $postalCode = trim($_POST["postalCode"]);}
    
    if(empty(trim($_POST["province"]))){
        $province_err = "Please enter your province.";
    } else{ $province = trim($_POST["province"]);}
    
    // Check input errors before inserting in database
    if(empty($firstName_err) && empty($lastName_err) && empty($companyName_err) && empty($profession_err) && empty($gender_err) && empty($phoneNumber_err) && empty($address_err) && empty($city_err) && empty($postalCode_err) && empty($province_err)){
        
        // Prepare an insert statement
        $sql = "INSERT INTO Profiles (userID, companyName, firstName, lastName, profession, gender, phoneNumber) VALUES (:id , :companyName, :firstName, :lastName, :profession, :gender, :phoneNumber)";
         
        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":id", $param_id, PDO::PARAM_STR);
            $stmt->bindParam(":companyName", $param_companyName, PDO::PARAM_STR);
            $stmt->bindParam(":firstName", $param_firstName, PDO::PARAM_STR);
            $stmt->bindParam(":lastName", $param_lastName, PDO::PARAM_STR);
            $stmt->bindParam(":profession", $param_profession, PDO::PARAM_STR);
            $stmt->bindParam(":gender", $param_gender, PDO::PARAM_STR);
            $stmt->bindParam(":phoneNumber", $param_phoneNumber, PDO::PARAM_STR);
            
            
            
            // Set parameters
            $param_id = $id;
            $param_companyName = $companyName;
            $param_firstName = $firstName;
            $param_lastName = $lastName;
            $param_profession = $profession;
            $param_gender = $gender;
            $param_phonNumber = $phoneNumber;
            
            // Attempt to execute the prepared statement
            if($stmt->execute()){
                $sql = "INSERT INTO Location (address, city, postalCode, province) VALUES(:address, :city, :postalCode, :province)";
                 if($stmt = $pdo->prepare($sql)){
                    // Bind variables to the prepared statement as parameters
                    $stmt->bindParam(":address", $param_address, PDO::PARAM_STR);
                    $stmt->bindParam(":city", $param_city, PDO::PARAM_STR);
                    $stmt->bindParam(":postalCode", $param_postalCode, PDO::PARAM_STR);
                    $stmt->bindParam(":province", $param_province, PDO::PARAM_STR);
                                    
                    // Set parameters
                    $param_address = $address;
                    $param_city = $city;
                    $param_postalCode = $postalCode;
                    $param_province = $province;
                    
                    if($stmt->execute()){
                        
                        //$sql = "UPDATE Profiles SET Profiles.locationID = Location.locationID 
                        //WHERE Profiles.userID = 
                        // Redirect to index page
                        if($_SESSION["usertype"] == 1 || $_SESSION["usertype"] == 2 || $_SESSION["usertype"] == 3){
                           header("location: index_employee.php");
                        }else if( $_SESSION["usertype"] == 4 || $_SESSION["usertype"] == 5)
                        {
                            header("location: index_employer.php");
                        }
                       
                    }                

                    }

            } else{
                echo "Oops! Something went wrong. Please try again later.";
            }

            // Close statement
            unset($stmt);
        }
    }
    
    // Close connection
    unset($pdo);
}
?>
 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Sign Up</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <style>
        body{ font: 14px sans-serif; }
        .wrapper{ width: 360px; padding: 20px; }
    </style>
</head>
<body>
    <div class="wrapper">
        <h2>Sign Up</h2>
        <p>Please fill this form to Update information.</p>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <div class="form-group">
                <label>Firtname</label>
                <input type="text" name="firstName" class="form-control <?php echo (!empty($firstName_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $firstName; ?>">
                <span class="invalid-feedback"><?php echo $firstName_err; ?></span>
            </div>    
            <div class="form-group">
                <label>Lastname</label>
                <input type="lastName" name="lastName" class="form-control <?php echo (!empty($lastName_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $lastName; ?>">
                <span class="invalid-feedback"><?php echo $lastName_err; ?></span>
            </div>
            <div class="form-group">
                <label>Company Name</label>
                <input type="companyName" name="companyName" class="form-control <?php echo (!empty($companyName_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $companyName; ?>">
                <span class="invalid-feedback"><?php echo $companyName_err; ?></span>
            </div>
            <div class="form-group">
                <label>Profession</label>
                <input type="profession" name="profession" class="form-control <?php echo (!empty($profession_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $profession; ?>">
                <span class="invalid-feedback"><?php echo $profession_err; ?></span>
            </div>
            <div class="form-group">
                <label>Gender</label>
                <input type="gender" name="gender" class="form-control <?php echo (!empty($gender_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $gender; ?>">
                <span class="invalid-feedback"><?php echo $gender_err; ?></span>
            </div>
            <div class="form-group">
                <label>Phone Number</label>
                <input type="phoneNumber" name="phoneNumber" class="form-control <?php echo (!empty($phoneNumber_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $phoneNumber; ?>">
                <span class="invalid-feedback"><?php echo $phoneNumber_err; ?></span>
            </div>
            <div class="form-group">
                <label>Address</label>
                <input type="address" name="address" class="form-control <?php echo (!empty($address_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $address; ?>">
                <span class="invalid-feedback"><?php echo $address_err; ?></span>
            </div>
            <div class="form-group">
                <label>City</label>
                <input type="city" name="city" class="form-control <?php echo (!empty($city_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $city; ?>">
                <span class="invalid-feedback"><?php echo $city_err; ?></span>
            </div>
            <div class="form-group">
                <label>Postal Code</label>
                <input type="postalCode" name="postalCode" class="form-control <?php echo (!empty($postalCode_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $postalCode; ?>">
                <span class="invalid-feedback"><?php echo $postalCode_err; ?></span>
            </div>
            <div class="form-group">
                <label>Province</label>
                <input type="province" name="province" class="form-control <?php echo (!empty($province_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $province; ?>">
                <span class="invalid-feedback"><?php echo $province_err; ?></span>
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-primary" value="Submit">
                <input type="reset" class="btn btn-secondary ml-2" value="Reset">
            </div>
            <p>Already filled your information? <a href="../">Back to Job search</a>.</p>
        </form>
