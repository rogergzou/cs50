<?php

    // configuration
    // require("../includes/config.php");
    require("../includes/config.php");
    require_once("PHPMailer/class.phpmailer.php");
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["email"]))
        {
            apologize("You must provide a username and a password and an email.");
        }
        else if ($_POST["password"] !== $_POST["confirmation"])
        {
            apologize("Your passwords must match.");
        }
        
        /*
        else if (query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 12345.67)", $_POST["username"], crypt($_POST["password"]))===false)
        {
            apologize("Query failed for some reason.");           
        }
        // assumes query worked and no errors found. also that elif executed query insert
        */
        else
        {
            /*$rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            
            // remember that user's now logged in by storing user's ID in session
            $_SESSION["id"] = $id;
            // require("login.php");
            // redirect to portfolio
            redirect("index.php"); */
            //require_once("PHPMailer/class.phpmailer.php");
                       
            $verz = rand() % 100;
            /*if (query("INSERT INTO verify (numbers) VALUES ($verz)", $verz)===false)
            {
                apologize("couldn't verify wtf idk y");
            }*/
            // instantiate mailer
            $mail = new PHPMailer();

            // use your ISP's SMTP server (e.g., smtp.fas.harvard.edu if on campus or smtp.comcast.net if off campus and your ISP is Comcast)
            $mail->IsSMTP();
            $mail->Host = /*"smtp.fas.harvard.edu"*/ "smtp.gmail.com";
            $mail->Port = 587;
            $mail->SMTPSecure = 'tls';
            $mail->SMTPAuth = true;
            $mail->Username = "ipod123432@gmail.com";
            $mail->Password = "lucyufaggot";
            
            // set From:
            // $mail->Username("ipod123432@gmail.com");
            $mail->SetFrom("ipod123432@gmail.com");
            

            // set To:
            $mail->AddAddress($_POST["email"]);

            // set Subject:
            $mail->Subject = "Account Confirmation";

            // set body
            $mail->Body = "<html><body>Hi there, this email is just to confirm your account. Your verification code is $verz.</body></html>";

            // set alternative body, in case user's mail client doesn't support HTML
            $mail->AltBody = "confirm account: verification code $verz";

            // send mail
            if ($mail->Send() === false)
                die($mail->ErrorInfo . "\n");
                        
            render("verify_form.php", ["title" => "Verify", "verz" => $verz, "user" => $_POST["username"], "pass" => $_POST["password"], "email" => $_POST["email"]]);
            }
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
