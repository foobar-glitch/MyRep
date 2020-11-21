<?php
	include("server_key.php");
	$db_host = "127.0.0.1";
    $db_user = "root";
    $db_database = "register";

	//encryption random par
	$ivlen = openssl_cipher_iv_length($cipher);
	$iv = openssl_random_pseudo_bytes($ivlen);
	
	if($_POST['username']===NULL || $_POST['password']===NULL){
		exit(1);
	}

	assert(isset($_POST['username'])&&!empty($_POST['username']));
	assert(isset($_POST['password'])&&!empty($_POST['password']));

	$username=$_POST['username'];
	$password=$_POST['password'];
	$conn = new PDO("mysql:host=$db_host;dbname=$db_database", $db_user);
	
	$stmt=$conn->prepare('SELECT * FROM logincred WHERE username=:un AND password=SHA2(:pw,256)');
	$stmt->execute(array(':un'=>$username, ':pw'=>$password));
	
	$sql_table = $stmt->fetchAll();
	if(count($sql_table)!=1){
		echo "Wrong crediantials, buddy";
		exit(1);
	}
	
	$credentials=$sql_table[0];
	$ciphertext = openssl_encrypt($credentials['username'], $cipher, $server_key, $options=0, $iv, $tag);
	
	echo "Welcome back,<br><b>".$credentials['username']."</b></br>";
	setcookie("user",bin2hex($ciphertext),time() + (86400 * 30),"/");
	setcookie("iv",bin2hex($iv),time() + (86400 * 30),"/");
	setcookie("tag",bin2hex($tag),time() + (86400 * 30),"/");
	session_start();
?>