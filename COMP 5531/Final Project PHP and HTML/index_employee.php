<?php
// Initialize the session
session_start();
 
// Check if the user is already logged in, if yes then redirect him to welcome page
if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] != true){
    header("location: Login.php");
    exit;
}

require_once 'Config.php';

$statement = $pdo->prepare('SELECT * FROM Jobs AS Jobs');
$statement->execute();

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Employee Portal</title>
</head>
<body>

    <h1 class="my-5">Hi, <b><?php echo htmlspecialchars($_SESSION["username"]); ?></b>. Welcome to Employee Portal.</h1>

    <div><a href="Update Info.php" class='btn btn-warning'>Update information of my Profile</a></div>
    <div><a href="Delete Profile.php" class='btn btn-primary'>Delete my Profile</a></div>

    <h4>All Jobs Available</h4>
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
                <td><a href="#">Apply For This Job</a></td>
            </tr>
        <?php } ?>
        }
        </tbody>
    </table>

    <div><a href="../">Go Back</a><div>

    <h4>Search For Jobs by Category Name</h4>
    
    <!-- (A) SEARCH FORM -->
    <form method="post">
    <label>Search</label>
    <input type="text" name="search">
    <input type="submit" name="submit">
    </form>

    <?php
    

    if (isset($_POST["submit"])) {
        $str = $_POST["search"];
        
        // Select what tuples will be in search pool 
        $statement = $pdo->prepare(
                    "SELECT * 
                    FROM wic55311.Jobs, wic55311.Job_Categories_List, wic55311.Job_Categories
                    WHERE Job_Categories_List.categoryName = '$str'
                    AND Jobs.jobID = Job_Categories.jobID 
                    AND Job_Categories.jobCategoryID = Job_Categories_List.jobCategoriesID
                    ");
    
        $statement->setFetchMode(PDO:: FETCH_OBJ);
        $statement -> execute();
    
        // Display Results to User
        if($row = $statement->fetch())
        {
            ?>
            <br><br><br>
            <table>
                <tr>
                    <th>Title</th>
                    <th>Description</th>
                    <th>Salary</th>
                </tr>
                <tr>
                    <td><?php echo $row->title; ?></td>
                    <td><?php echo $row->description;?></td>
                    <td><?php echo $row->salary;?></td>
                </tr>
    
            </table>
    <?php 
        }
            
            
            else{
                echo "No Matching Jobs Found";
            }
    
    
    }
    
    ?>
    
    <h4>Search For Jobs by Title</h4>
    
    <!-- (A) SEARCH FORM -->
<form method="post">
    <label>Search</label>
    <input type="text" name="search">
    <input type="submit" name="submit">
    </form>

    <?php

    if (isset($_POST["submit"])) {
        $str = $_POST["search"];

        
        // Select what tuples will be in search pool 
        $statement = $pdo->prepare(
                    "SELECT * 
                    FROM wic55311.Jobs
                    WHERE Jobs.title LIKE '%$str%'
                    ");
    
        $statement->setFetchMode(PDO:: FETCH_OBJ);
        $statement -> execute();
    
        // Display Results to User
    if ($row = $statement->fetch())
        while($row = $statement->fetch())
        {
            ?>
            <br><br><br>
            <table>
                <tr>
                    <th>Title</th>
                    <th>Description</th>
                    <th>Salary</th>
                </tr>
                <tr>
                    <td><?php echo $row->title; ?></td>
                    <td><?php echo $row->description;?></td>
                    <td><?php echo $row->salary;?></td>
                </tr>
    
            </table>
    <?php 
        }
            
            
            else{
                echo "No Matching Jobs Found";
            }
    
    
    }
    
    ?>
    

    <p>
        <a href="../Password Reset.php" class="btn btn-warning">Reset Your Password</a>
        <a href="../Logout.php" class="btn btn-danger ml-3">Sign Out of Your Account</a>
    </p>
    <div><a href="../">Go Back</a><div>
    <p>Having Trouble? Contact us at 514-555-1900 for 24/h help line.</p>
</body>
</html>