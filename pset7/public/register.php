<?php

    // configuration
    require("../includes/config.php");
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // checks to make sure username field was filled
        if (empty($_POST["user"]))
        {
            apologize("Username field left blank");
        }
        
        // checks to make sure both password fields were filled
        if (empty($_POST["password"]) || empty($_POST["confirmation"]))
        {
            apologize("One or both password fields left blank");
        }
        
        // checks to make sure two password fields match
        if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Passwords do not match!");
        }
        
        // enters user information into SQL database
        $result = query("INSERT INTO users (user, hash) VALUES(?, ?)",
        $_POST["user"], crypt($_POST["password"]));
        
        // checks to see if username already exists in database
        if ($result === false)
        {
            apologize("Username already taken");
        }
        
        // automatically logs user in
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        $_SESSION["id"] = $id;
        
        // add user to expenses table
        query("INSERT INTO expenses (id) VALUES(?)", $_SESSION["id"]);
        
        // redirects to portfolio
        redirect("/");
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }
    
?>
