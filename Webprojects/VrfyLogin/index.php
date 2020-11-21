<?php
	include("../register/php/server_key.php");
	
	if($_COOKIE['user']===NULL || $_COOKIE['tag']===NULL || $_COOKIE['iv']===NULL){
		echo "Cookie not correctly set";
		exit(1);
	}
	
	$enc_un=pack('H*', $_COOKIE['user']);
	$tag=pack('H*',$_COOKIE['tag']);
	$iv=pack('H*',$_COOKIE['iv']);
	//get username
	$dec_un=openssl_decrypt($enc_un, $cipher, $server_key, $options=0, $iv, $tag);
	
	$db_host = "127.0.0.1";
    $db_user = "root";
    $db_database = "register";
	
	
	$conn = new PDO("mysql:host=$db_host;dbname=$db_database", $db_user);
	$stmt=$conn->prepare('SELECT * FROM logincred WHERE username=:un');
	$stmt->execute(array(':un'=>$dec_un));
	$sql_table = $stmt->fetchAll();
	if(count($sql_table)!=1){
		die("Wrong Cookie");
	}
	else{
		echo "HELLO, <br><b>".$dec_un."</b></br>";
	}
?>