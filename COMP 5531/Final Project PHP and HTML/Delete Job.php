<?php require_once 'Config.php';

$statement = $pdo->prepare("SELECT * FROM wic55311.Jobs AS job WHERE job.jobID = :jobID");
$statement->bindParam(":jobID", $_GET["jobID"]);
$statement->execute();
$job = $statement->fetch(PDO::FETCH_ASSOC);

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

<h4>Delete Job Posting</h4>


<form method="post">
<?php

// show message to user
$title = $job["title"];
$ID = $job["jobID"];
echo("Are you sure you want to delete ");
echo($title);
echo"<br>";

?>
<input type="submit" name="confirm" value="Yes"><br/>
<input type="submit" name="confirm" value="No"><br/>
<?php

if (isset($_POST['confirm'])) {
    if ($_POST['confirm'] == 'Yes') {

        $sql = $pdo->prepare("DELETE FROM wic55311.Jobs WHERE Jobs.jobID = :ID");
        $sql->bindParam(":ID", $param_ID);
        $param_ID = $job["jobID"];
        $sql -> execute();
            echo "Job Successfully Deleted. You may now Go Back.";
        

        
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