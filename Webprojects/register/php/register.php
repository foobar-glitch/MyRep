<?php
	$db_host = "127.0.0.1";
    $db_user = "root";
    $db_database = "register";
	
	$username=$_POST['username'];
	$password=$_POST['password'];
	$conf=$_POST['confirm_password'];
	
	
	if($username==NULL || $password==NULL){
		die("No Username or Password set");
	}
	if($conf!=$password){
		//echo "Wrong password. Redirecting...";
		//sleep(2);
		//header("Location: ../register.html");
		die("Passwords don't match<br><a href='../register.html'>Click here to go back</a>");
		//exit(1);
	}
	
	assert(isset($username)&&!empty($username));
	assert(isset($password)&&!empty($password));
	
	$conn = new PDO("mysql:host=$db_host;dbname=$db_database", $db_user);
	$stmt=$conn->prepare('SELECT * FROM logincred WHERE username=:un');
	$stmt->execute(array(':un'=>$username));
	
	$sql_table = $stmt->fetchAll();
	if(count($sql_table)!=0){
		die('Username is already taken');
	}
	//un: username; pw: password
	$stmt=$conn->prepare('INSERT INTO logincred (username,password) VALUES (:un,SHA2(:pw,256))');
	$stmt->execute(array(':un'=>$username, ':pw'=>$password));
	
	header("Location: ../index.html");
	//ALTER TABLE `logincred` AUTO_INCREMENT=1
?>