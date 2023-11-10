<?php

/*echo "Hello! test is ok";*/


$hostname = "localhost";
$username = "root";
$password = "";
$database = "sensor_db";

$conn = mysqli_connect($hostname, $username, $password, $database);

if(!$conn){
	die("connection failed: " . mysqli_connect_error());
}
echo "database connection is ok";

if(isset($_POST["tempreture"]) && isset($_POST["humidity"])){
	
	$t = $_POST["tempreture"];
	$h = $_POST["humidity"];
	
	$sql = "INSERT INTO dht11 (tempreture, humidity) VALUES (".$t.",".$h.")";

	if(mysqli_query($conn,$sql)){
		echo"\nNew record created sucessfully";
	}
	else{
		echo "Error: " . $sql . "<br>" . mysqli_error($conn); 
	}
}
?>