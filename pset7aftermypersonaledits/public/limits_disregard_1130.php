<?php

    // configuration
    require("../includes/config.php");
    // if form was submitted
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["limit"]) || empty($_POST["category"]))
        {
            apologize("You must provide a limit and a category.");
        }
        /*else*/ 
        
        $catz = $_POST["category"];
        $limz = $_POST["limit"];
        $idz = $_SESSION["id"];
        if (/*query("INSERT INTO limits (id, limit, category) VALUES(?, ?, ?)", $_SESSION["id"], $_POST["limit"], $_POST["category"])*/
        
        query("ALTER TABLE `limits` ADD `$catz` DECIMAL (65, 4) UNSIGNED NOT NULL DEFAULT 0") === false )
        //query("ALTER TABLE limits ADD '?' DECIMAL( 65, 4 ) UNSIGNED NOT NULL DEFAULT 0" /*ADD UNIQUE ?, $_POST["category"] */, $_POST["category"])===false)
        
        //query ("ALTER TABLE limits ADD tax date") ===false  )
        {
            // probably indicates duplicate but w/e
            // #1060 - Duplicate column name 'food' 
            // apologize("Query failed for some reason.");           
        }
        // query ("ALTER TABLE limits ADD tax date");
        if (query("UPDATE limits SET `$catz` = ? WHERE id = ?", /*$catz,*/ $limz, $idz/*", $_POST["category"], $_POST["limit"], $_SESSION["id"]*/) === false)
        //if (false)
        {
            apologize("Query update failed for some reason."); 
        }
        // assumes query worked and no errors found. also that elif executed query insert
        /*else*/
        
            // $rows = query("SELECT LAST_INSERT_ID() AS id");
            // $id = $rows[0]["id"];
            
            // remember that user's now logged in by storing user's ID in session
            // $_SESSION["id"] = $id;
            // require("login.php");
            // redirect to portfolio
            redirect("index.php");
        
    }
    else
    {
        // else render form
        render("limits_form.php", ["title" => "limits"]);
    }

?>
