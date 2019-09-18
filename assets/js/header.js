(function () {
  var header = document.querySelector(".md-header");
  var materialDesignStateAttributeName = "data-md-state";
  var threshold = 35;

  function clearMaterialDesignNavbarShadow() {
    var position = this.scrollY;
    var attributeValue = !!header.getAttribute(materialDesignStateAttributeName);

    if (position < threshold && attributeValue) {
      header.setAttribute(materialDesignStateAttributeName, "");
    } else if (position > threshold && !attributeValue) {
      header.setAttribute(materialDesignStateAttributeName, "shadow");
    }
  }

  window.addEventListener("scroll", clearMaterialDesignNavbarShadow);
  clearMaterialDesignNavbarShadow();
})();
