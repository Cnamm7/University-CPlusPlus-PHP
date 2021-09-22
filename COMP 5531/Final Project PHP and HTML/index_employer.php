<?php require_once 'Config.php';
// Initialize the session
session_start();
 
// Check if the user is logged in, if not then redirect him to login page
if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
    header("location: Login.php");
    exit;
}
$statement = $pdo->prepare('SELECT * FROM wic55311.Jobs AS Jobs');
$statement->execute();

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Employer Portal</title>
</head>
<body>
    <h1> Hi, <b><?php echo htmlspecialchars($_SESSION["username"]); ?></b>. Welcome to Employee Portal.</h1>

    <h4>All Jobs Postings</h4>
    <table>
        <thead>
            <tr>
                <td>title</td>
                <td>salary</td>
                <td>positionsAvailable</td>
                <td>datePosted</td>
                <td>status</td>
            </tr>
        </thead>
        <tbody>
        <?php while ($row = $statement->fetch(PDO::FETCH_ASSOC, PDO::FETCH_ORI_NEXT)) { ?>
            <tr>
                <td><?= $row["title"] ?></td>
                <td><?= $row["salary"] ?></td>
                <td><?= $row["positionsAvailable"] ?></td>
                <td><?= $row["datePosted"] ?></td>
                <td><?= $row["status"] ?></td>
                <td>
                    <a href="#">Edit</a>
                    <a href="Delete Job.php">Delete</a>
                </td>
            </tr>
        <?php } ?>
        }
        </tbody>
    </table>

    <a href="create_job.php" class='btn btn-primary'>Post New Job</a>
    
    <div><a href="Login.php" class='btn btn-primary'>See Current Application</a></div>
    
    <div><a href="Login.php" class='btn btn-primary'>Change User Category</a><div>

    <div><a href="Login.php">Go Back</a><div>

    <p>Having Trouble? Contact us at 514-555-1900 for 24/h help line.</p>

</body>
</html>