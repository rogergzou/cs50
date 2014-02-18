<form action="register.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus name="username" placeholder="Username" type="text"/>
        </div>
        <div class="form-group">
            <input name="password" placeholder="Password" type="password"/>
            <div class="confirmation">
                <input name="confirmation" placeholder="Password" type="password"/>
            </div>
        </div>
        <div class="form-group">
            <input name="email" placeholder="email@website.com" type="text"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Register</button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="login.php">log in</a>
</div>
