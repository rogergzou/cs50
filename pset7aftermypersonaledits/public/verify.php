<?php
require("../includes/config.php");
if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["code"]))
        {
            apologize("You must provide a username and a password and an email.");
        }
        else if ($_POST["code"] == $verz)
        {
            if (query("INSERT INTO users (username, hash, email) VALUES(?, ?, ?)", $user, crypt($pass), $email)===false)
            {
                apologize("Query failed for some reason.");           
            }
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            
            // remember that user's now logged in by storing user's ID in session
            $_SESSION["id"] = $id;
            // require("login.php");
            // redirect to portfolio
            redirect("index.php");
        }
    }






?>
