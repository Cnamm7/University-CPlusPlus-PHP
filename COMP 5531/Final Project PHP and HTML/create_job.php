<?php require_once 'Config.php';

// Check if user passed all required data 

    if(isset($_POST["jobID"])
        && isset($_POST["userID"])
        && isset($_POST["locationID"])
        && isset($_POST["title"])
        && isset($_POST["salary"])
        && isset($_POST["description"])
        && isset($_POST["positionsAvailable"])
        && isset($_POST["datePosted"])
        && isset($_POST["status"])
    ) {
        $Jobs = $pdo->prepare("INSERT INTO wic5531.Jobs (jobID, userID, locationID, title,
        salary, description, positionsAvailable, datePosted, status)
        VALUES (jobID, userID, locationID, title,
        salary, description, positionsAvailable, datePosted, status);");

        $Jobs->bindParam('jobID', $_Post["jobID"]);
        $Jobs->bindParam('userID', $_Post["userID"]);
        $Jobs->bindParam('locationID', $_Post["locationID"]);
        $Jobs->bindParam('title', $_Post["title"]);
        $Jobs->bindParam('salary', $_Post["salary"]);
        $Jobs->bindParam('description', $_Post["description"]);
        $Jobs->bindParam('positionsAvailable', $_Post["positionsAvailable"]);
        $Jobs->bindParam('datePosted', $_Post["datePosted"]);
        $Jobs->bindParam('status', $_Post["status"]);

        if($Jobs->execute()) {
            header("Location: ."); // go back
        }
        
    }

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Create a New Job</title>
</head>
<body>

    <h2>Create a New Job</h2>
    <form action="./create_job.php" method="post">
    
        <label for="jobID">Job ID</label><br>
        <input type="number" name="jobID" id="jobID"> <br>

        <label for="userID">User ID</label><br>
        <input type="text" name="userID" id="userID"> <br>

        <label for="locationID">Location ID</label><br>
        <input type="text" name="locationID" id="locationID"> <br>

        <label for="title">Job Title</label><br>
        <input type="text" name="title" id="title"> <br>

        <label for="salary">Salary</label><br>
        <input type="number" name="salary" id="salary"> <br>

        <label for="description">Desc</label><br>
        <input type="text" name="description" id="description"> <br>

        <label for="positionsAvailable">Positions Available</label><br>
        <input type="number" name="positionsAvailable" id="positionsAvailable"> <br>

        <label for="datePosted">Date</label><br>
        <input type="timeStamp" name="datePosted" id="datePosted"> <br>

        <label for="status">Status</label><br>
        <input type="text" name="status" id="status"> <br>

        <button type="submit">Add Job</button>

        <a href="./">Back</a>

        
    
    </form>

    
</body>
</html>