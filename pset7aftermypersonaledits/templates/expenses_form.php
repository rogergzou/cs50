<div>
            <select>
                <?php
                    // SQL command returns multidimensional array
                    foreach ($categories as $category)
                    {
                        foreach ($category as $name)
                        {
                            echo "<option>" . $name . "</option>";
                        }
                    }
                ?>
            </select>
        </div>
        
        
        
        
<form action="expenses.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus name="category" placeholder="Category" type="text"/>
        </div>
        <div class="form-group">
            <input autofocus name="expense" placeholder="0.00" type="text"/>
        </div>
        <?php /*<div class="form-group">
            <input autofocus name="shares" placeholder="Shares" type="text"/>
        </div> */ ?>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Submit Expense</button>
        </div>
    </fieldset>
</form>
