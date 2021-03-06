<?php
require_once('inc/permissions.inc');
require_once('inc/roles.inc');

if (!isset($_SESSION['role'])) {
  $_SESSION['role'] = '';
}

if (!isset($_SESSION['permissions'])) {
  $_SESSION['permissions'] = $roles['']['permissions'];
}

if (isset($_SESSION['setting_up'])) {
  $_SESSION['permissions'] |= SET_UP_PERMISSION;
}

// This only works where a header can appear...
function require_permission($perm) {
  if (($_SESSION['permissions'] & $perm) == 0) {
    header('Location: login.php');
    exit(0);
  }
}

function have_permission($perm) {
  return ($_SESSION['permissions'] & $perm) != 0;
}
?>
