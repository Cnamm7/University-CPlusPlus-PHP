<?php 
session_start();
require_once 'Config.php';

// Check if the user is logged in, if not then redirect him to login page
if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
    header("location: ../Login.php");
    exit;
}


//$stmt = $pdo->prepare('DELETE FROM wic55311.Users
                        //WHERE Users.userID = :id');

//$stmt->bindParam(":id", $id);
//$id = $_SESSION["id"];

//if ($stmt->execute()) {
//    header("Login.php");
//} else {
    //$message = 'Sorry, entered values are not correct.';
//    echo "hey you!";
//}

$statement = $pdo->prepare("SELECT * FROM wic55311.Users WHERE Users.userID = :userID");
$statement->bindParam(":userID", $_GET["userID"]);
$statement->execute();
$User = $statement->fetch(PDO::FETCH_ASSOC);


?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Delete Job Posting</title>
</head>
<body>

<h4>Delete User</h4>


<form method="post">
<?php

// show message to user
$title = $User["userID"];
$ID = $User["userNumber"];
echo("Are you sure you want to delete ");
echo($title);
echo"<br>";

?>
<input type="submit" name="confirm" value="Yes"><br/>
<input type="submit" name="confirm" value="No"><br/>
<?php

if (isset($_POST['confirm'])) {
    if ($_POST['confirm'] == 'Yes') {

        $sql = $pdo->prepare("DELETE FROM wic55311.Users WHERE Users.userID = :title");
        $sql->bindParam(":title", $param_userID);
        $param_userID = $User["userID"];
        $sql -> execute();
            echo "User Successfully Deleted. You may now Go Back.";
        

        session_destroy();
    }
    else if ($_POST['confirm'] == 'No') {
        header('Location: ./');
    } 
}


?>
</form>

<a href="./">Back</a>
    
</body>
</html>